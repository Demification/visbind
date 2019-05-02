#include "pixbit.h"

#include <intrin.h>
#include <stdint.h>

#pragma warning(disable:4996)
#pragma warning(disable:4793)

#include <chrono>
#include <iostream>
std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
#define BENCHMARK_START start = std::chrono::high_resolution_clock::now();
#define BENCHMARK_STOP  stop = std::chrono::high_resolution_clock::now();std::cout << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count()<< " microseconds" << std::endl;

namespace pixbit
{
	RGBQUAD bitmap::getpix(const UINT x, const UINT y)
	{
		return ptr[max_width*y + x];
	}

	void bitmap::setpix(const RGBQUAD c, const UINT x, const UINT y)
	{
		ptr[max_width*y + x] = c;
	}

	void* bitmap::init(size_t max_width, size_t max_height)
	{
		this->width = 0;
		this->height = 0;

		this->max_width = max_width;
		this->max_height = max_height;

		unsigned int size = max_width % 16;
		if (size)
		{
			size = 16 - size;
			this->max_width = max_width + size;
		}

		size = max_height % 16;
		if (size)
		{
			size = 16 - size;
			this->max_height = max_height + size;
		}

		sizebytes = this->max_width * this->max_height * sizeof(RGBQUAD);

		ptr = (RGBQUAD*)buffer.init(sizebytes);

		return ptr;
	}

	void bitmap::destroy()
	{
		if (gditoken) 
			Gdiplus::GdiplusShutdown(gditoken);
		if (hBitmap)
		{
			DeleteObject(hBitmap);
			hBitmap = nullptr;
		}

		ptr = nullptr;
		width = 0;
		height = 0;
		max_height = 0;
		max_width = 0;
		buffer.destroy();

		
	}

	void bitmap::clear()
	{
		this->buffer.memset0();
	}

	void bitmap::load(wchar_t* path)
	{
		if (!path)return;

		if (!gditoken)
		{
			Gdiplus::GdiplusStartupInput gdiplusStartupInput;
			Gdiplus::GdiplusStartup(&gditoken, &gdiplusStartupInput, NULL);
		}

		Gdiplus::Bitmap *bitmapGdi32bpp = nullptr;

		Gdiplus::Bitmap *bitmap = Gdiplus::Bitmap::FromFile(path);
		width = bitmap->GetWidth();
		height = bitmap->GetHeight();
		Gdiplus::Rect no_strech_rect(0, 0, (int)width, (int)height);
		Gdiplus::Graphics *graphics = new Gdiplus::Graphics(bitmap);
		graphics->DrawImage(bitmap, no_strech_rect);
		delete graphics;

		if (width > this->max_width) width = this->max_width;
		if (height > this->max_height) height = this->max_height;

		Gdiplus::Rect rect(0, 0, (INT)width, (INT)height);
		bitmapGdi32bpp = bitmap->Clone(rect, PixelFormat32bppARGB);

		clear();

		Gdiplus::BitmapData* bitmapData = new Gdiplus::BitmapData;
		bitmapGdi32bpp->LockBits(&rect, Gdiplus::ImageLockMode::ImageLockModeRead, PixelFormat32bppARGB, bitmapData);

		RGBQUAD *dest = ptr;
		RGBQUAD *scr = (RGBQUAD *)bitmapData->Scan0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				dest[y * max_width + x] = scr[y * width + x];
			}
		}

		bitmapGdi32bpp->UnlockBits(bitmapData);

		delete bitmapData;
		delete bitmap;
		delete bitmapGdi32bpp;
	}

	void bitmap::save(wchar_t* path)
	{
		FILE* pFile = _wfopen(path, L"wb"); // wb -> w: writable b: binary, open as writable and binary
		if (pFile == NULL) {
			return;
		}

		BITMAPINFOHEADER BMIH = { 0 };                         // BMP header
		BMIH.biSize = sizeof(BITMAPINFOHEADER);
		BMIH.biSizeImage = (DWORD)(width * height * 4);

		BMIH.biSize = sizeof(BITMAPINFOHEADER);
		BMIH.biWidth = (LONG)width;
		BMIH.biHeight = -((INT)height);
		BMIH.biPlanes = 1;
		BMIH.biBitCount = 32;
		BMIH.biCompression = BI_RGB;

		BITMAPFILEHEADER bmfh = { 0 };                         // Other BMP header
		int nBitsOffset = sizeof(BITMAPFILEHEADER) + BMIH.biSize;
		LONG lImageSize = BMIH.biSizeImage;
		LONG lFileSize = nBitsOffset + lImageSize;
		bmfh.bfType = 'B' + ('M' << 8);
		bmfh.bfOffBits = nBitsOffset;
		bmfh.bfSize = lFileSize;
		bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

		size_t nWrittenFileHeaderSize = fwrite(&bmfh, 1, sizeof(BITMAPFILEHEADER), pFile);

		size_t nWrittenInfoHeaderSize = fwrite(&BMIH, 1, sizeof(BITMAPINFOHEADER), pFile);

		RGBQUAD *lpBits = (RGBQUAD *)alloca(BMIH.biSizeImage);
		RGBQUAD *b = (RGBQUAD *)ptr;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				lpBits[y*width + x] = b[y*max_width + x];
			}
		}

		size_t nWrittenDIBDataSize = fwrite(lpBits, 1, lImageSize, pFile);
		fclose(pFile); // closing the file.
	}

	void bitmap::load(HWND hwnd, size_t x_pos, size_t y_pos, size_t width, size_t height)
	{
		if (width > this->max_width) width = this->max_width;
		if (height > this->max_height) height = this->max_height;

		this->height = height;
		this->width = width;

		BITMAPINFOHEADER bmpInfoHeader = { 0 };
		BITMAPINFO info = { 0 };

		RECT rect;
		GetClientRect(hwnd, &rect);
		int whw = rect.right - rect.left;
		int hhw = rect.bottom - rect.top;

		bmpInfoHeader.biSize = sizeof(bmpInfoHeader);
		bmpInfoHeader.biWidth = (LONG)width;
		bmpInfoHeader.biHeight = -(LONG)height;
		bmpInfoHeader.biPlanes = 1;
		bmpInfoHeader.biBitCount = 32;
		bmpInfoHeader.biCompression = BI_RGB;
		bmpInfoHeader.biSizeImage = (DWORD)(width * height * 4);
		info.bmiHeader = bmpInfoHeader;

		HDC dchw = GetDC(hwnd);
		HDC dctmp = CreateCompatibleDC(dchw);
		void *memory;
		HBITMAP hBitmap = CreateDIBSection(dchw, &info, DIB_RGB_COLORS, &memory, NULL, 0);
		SelectObject(dctmp, hBitmap);
		BitBlt(dctmp, 0, 0, (int)width, (int)height, dchw, (int)x_pos, (int)y_pos, SRCCOPY);

		//memcpy(ptr, memory, width*height * 4);

		RGBQUAD *rgbq_memory = (RGBQUAD*) memory;
		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				ptr[y*max_width + x] = rgbq_memory[y*width + x];
			}
		}

		ReleaseDC(hwnd, dchw);

		DeleteObject(hBitmap);
		DeleteDC(dctmp);

	}

	void bitmap::load8gbpp(const BYTE* src8bpp, const size_t width, const size_t height)
	{
		RGBQUAD* ptr = (RGBQUAD*)buffer.get0ptr();

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				register size_t i = y * max_width + x;
				ptr[i].rgbBlue = src8bpp[i];
				ptr[i].rgbGreen = src8bpp[i];
				ptr[i].rgbRed = src8bpp[i];
			}
		}

		this->width = width;
		this->height = height;
	}

	void* bitmap::get0ptr()
	{
		return buffer.get0ptr();
	}

	void bitmap::initAndLoad(UINT IDB_RESOURCE_BITMAP)
	{
		HANDLE hBitmap = LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_RESOURCE_BITMAP), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE);

		BITMAP bitmap = { 0 };
		GetObject(hBitmap, sizeof(BITMAP), &bitmap);

		if (bitmap.bmBitsPixel == 32)
		{
			max_height = bitmap.bmHeight;
			max_width = bitmap.bmWidth;


			size_t size = max_width % 16;
			if (size)
			{
				size = 16 - size;
				this->max_width = max_width + size;
			}

			size = max_height % 16;
			if (size)
			{
				size = 16 - size;
				this->max_height = max_height + size;
			}

			size = max_height * max_width * 4;

			GetBitmapBits((HBITMAP)hBitmap, (LONG)size, init(max_width, max_height));
		}

		this->height = max_height;
		this->width = max_width;

		DeleteObject(hBitmap);
	}

	HBITMAP bitmap::getHBitmap()
	{
		if (hBitmap)
		{
			DeleteObject(hBitmap);
		}
		hBitmap = CreateBitmap((int)max_width, (int)max_height, 1, 32, get0ptr());
		return hBitmap;
	}


	void bmpcmp::init(size_t max_width, size_t max_height)
	{
		this->max_width = max_width;
		this->max_height = max_height;

		size_t size = max_width % 16;
		if (size)
		{
			size = 16 - size;
			this->max_width = max_width + size;
		}

		size = max_height % 16;
		if (size)
		{
			size = 16 - size;
			this->max_height = max_height + size;
		}

		size = this->max_width * this->max_height;
		sizebytes = size;

		array4x8bit.init(size, 4);

		r8bpp = (BYTE*)array4x8bit.allocate()->ptr;
		g8bpp = (BYTE*)array4x8bit.allocate()->ptr;
		b8bpp = (BYTE*)array4x8bit.allocate()->ptr;
		grey8bpp = (BYTE*)array4x8bit.allocate()->ptr;
	}

	void bmpcmp::destroy()
	{
		array4x8bit.destroy();
	}

	void bmpcmp::load8bpp(bitmap* src32bpp)
	{
		register unsigned __int32* r = (unsigned __int32*)r8bpp;
		register unsigned __int32* g = (unsigned __int32*)g8bpp;
		register unsigned __int32* b = (unsigned __int32*)b8bpp;

		register unsigned __int8* dest = (unsigned __int8*)src32bpp->get0ptr();

		register const __m128i mask = _mm_set_epi8(15, 11, 7, 3, 14, 10, 6, 2, 13, 9, 5, 1, 12, 8, 4, 0);

		for (size_t i = 0; i < src32bpp->sizebytes; i = i + 16)
		{
			__m128i pix32b128 = _mm_loadu_si128((__m128i*)&dest[i]);
			__m128i pix8x4b128 = _mm_shuffle_epi8(pix32b128, mask);

			*r = pix8x4b128.m128i_i32[2];
			*g = pix8x4b128.m128i_i32[1];
			*b = pix8x4b128.m128i_i32[0];
			++r; ++g; ++b;
		}
	}

	BYTE* bmpcmp::load8bppgrey()
	{
		__m128i* a = (__m128i*)grey8bpp;

		register unsigned __int8* r = (unsigned __int8*)r8bpp;
		register unsigned __int8* g = (unsigned __int8*)g8bpp;
		register unsigned __int8* b = (unsigned __int8*)b8bpp;

		register uint8_t n = 9;
		register __m128i inv = _mm_set1_epi16((1 << n) / 3 + 1);

		register __m128i lo, hi;

		register __m128i blue8x16b128;
		register __m128i green8x16b128;
		register __m128i red8x16b128;

		register const __m128i zero128i = _mm_setzero_si128();

		for (unsigned int i = 0; i < sizebytes-16; i = i + 16)
		{
			blue8x16b128 = _mm_loadu_si128((__m128i*)&b[i]);
			lo = _mm_unpacklo_epi8(blue8x16b128, zero128i);
			hi = _mm_unpackhi_epi8(blue8x16b128, zero128i);
			lo = _mm_srli_epi16(_mm_mullo_epi16(lo, inv), n);
			hi = _mm_srli_epi16(_mm_mullo_epi16(hi, inv), n);
			blue8x16b128 = _mm_packus_epi16(lo, hi);

			green8x16b128 = _mm_loadu_si128((__m128i*)&g[i]);
			lo = _mm_unpacklo_epi8(green8x16b128, zero128i);
			hi = _mm_unpackhi_epi8(green8x16b128, zero128i);
			lo = _mm_srli_epi16(_mm_mullo_epi16(lo, inv), n);
			hi = _mm_srli_epi16(_mm_mullo_epi16(hi, inv), n);
			green8x16b128 = _mm_packus_epi16(lo, hi);

			red8x16b128 = _mm_loadu_si128((__m128i*)&r[i]);
			lo = _mm_unpacklo_epi8(red8x16b128, zero128i);
			hi = _mm_unpackhi_epi8(red8x16b128, zero128i);
			lo = _mm_srli_epi16(_mm_mullo_epi16(lo, inv), n);
			hi = _mm_srli_epi16(_mm_mullo_epi16(hi, inv), n);
			red8x16b128 = _mm_packus_epi16(lo, hi);

			__m128i a8x16b128 = _mm_add_epi8(red8x16b128, green8x16b128);
			a8x16b128 = _mm_add_epi8(a8x16b128, blue8x16b128);

			_mm_storeu_si128(a, a8x16b128);
			++a;
		}

		return (BYTE*)grey8bpp;
	}

	void bmpcmp::copy8to32bpp(bitmap* dest32bpp, rgb channel, bool greyscale = false)
	{
		switch (channel)
		{
		case rgb::blue:
			copy8to32bpp(dest32bpp, b8bpp, 0, greyscale);
			break;
		case rgb::green:
			copy8to32bpp(dest32bpp, g8bpp, 1, greyscale);
			break;
		case rgb::red:
			copy8to32bpp(dest32bpp, r8bpp, 2, greyscale);
			break;
		case rgb::grey:
			copy8to32bpp(dest32bpp, grey8bpp, 0, true);
			break;
		}
	}

	void bmpcmp::copy8to32bpp(bitmap* dest32bpp)
	{
		register unsigned __int8* r = (unsigned __int8*)r8bpp;
		register unsigned __int8* g = (unsigned __int8*)g8bpp;
		register unsigned __int8* b = (unsigned __int8*)b8bpp;

		register unsigned __int32* dest = (unsigned __int32*)dest32bpp->get0ptr();

		register __m128i mask = _mm_set_epi8(15, 11, 7, 3, 14, 10, 6, 2, 13, 9, 5, 1, 12, 8, 4, 0);

		for (UINT i = 0; i < max_width*max_height - 4; i = i + 4)
		{
			register __m128i pix8x16 = _mm_setr_epi32(*(__int32*)&b[i], *(__int32*)&g[i], *(__int32*)&r[i], 0);
			pix8x16 = _mm_shuffle_epi8(pix8x16, mask);

			_mm_storeu_si128((__m128i*)&dest[i], pix8x16);
		}

		dest32bpp->width = max_width;
		dest32bpp->height = max_height;
	}

	void bmpcmp::copy8to32bpp(bitmap* dest32bpp, BYTE *src8bpp, BYTE nByte, bool greyscale)
	{
		unsigned __int8* a = (unsigned __int8*)src8bpp;

		if (greyscale)
		{
			unsigned __int32* b = (unsigned __int32*)dest32bpp->get0ptr();

			for (size_t i = 0; i < sizebytes; i++)
			{
				((__int8*)&b[i])[0] = a[i];
				((__int8*)&b[i])[1] = a[i];
				((__int8*)&b[i])[2] = a[i];
			}
		}
		else
		{
			unsigned __int8* b = (unsigned __int8*)dest32bpp->get0ptr();

			for (size_t i = 0; i < sizebytes; i++)
			{
				b[i * 4 + nByte] = a[i];
			}
		}

		dest32bpp->width = max_width;
		dest32bpp->height = max_height;
	}

}