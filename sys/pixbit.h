#pragma once
#include "allocator.h"

#include <gdiplus.h>
#include <stdio.h>

#pragma comment( lib, "gdiplus.lib" ) 
#pragma comment( lib, "gdi32.lib" ) 
#pragma comment( lib, "user32.lib" ) 

namespace pixbit
{
	class bitmap
	{
	protected:
		HBITMAP hBitmap = nullptr;
		RGBQUAD * ptr = nullptr;
		ULONG_PTR gditoken = NULL;

	public:
		size_t max_width;
		size_t max_height;

		size_t sizebytes;

		size_t width;
		size_t height;

		alc::allocator buffer;

		__forceinline RGBQUAD getpix(const UINT x, const UINT y);

		__forceinline void setpix(const RGBQUAD c, const UINT x, const UINT y);

		__forceinline RGBQUAD operator[] (const UINT index) const { return ptr[index]; };


		void* init(size_t max_width, size_t max_height);

		void destroy();

		void clear();

		void load(wchar_t* path);

		void initAndLoad(UINT IDB_RESOURCE_BITMAP);

		void save(wchar_t* path);

		void load(HWND hwnd, size_t x_pos, size_t y_pos, size_t width, size_t height);

		void load8gbpp(const BYTE* src8bpp, const size_t width, const size_t height);

		void* get0ptr();

		HBITMAP getHBitmap();

	};

	
	enum rgb { blue, green, red, grey };

	class bmpcmp
	{
	public:
		size_t sizebytes;

		size_t max_width;
		size_t max_height;
	
		void init(size_t max_width, size_t max_height);

		void destroy();

		alc::allocator array4x8bit;

		BYTE* r8bpp;
		BYTE* g8bpp;
		BYTE* b8bpp;
		BYTE* grey8bpp;

		void load8bpp(bitmap* src32bpp);

		BYTE* load8bppgrey();

		void copy8to32bpp(bitmap* dest32bpp, rgb channel, bool greyscale);

		void copy8to32bpp(bitmap* dest32bpp);

	private:
		void copy8to32bpp(bitmap* dest32bpp, BYTE* src8bpp, BYTE nByte, bool greyscale);

	};



}

