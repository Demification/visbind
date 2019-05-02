#include "support.h"
#include <windows.h>
#pragma warning( disable : 4267)

namespace support {
	using namespace System;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	Bitmap^ copyArgbArrayToBitmapArgb(void* ptr, size_t w, size_t h)
	{
		using namespace System::Drawing::Imaging;
		Bitmap^ bitmap = gcnew Bitmap(w, h, PixelFormat::Format32bppRgb);
		BitmapData^ data = bitmap->LockBits(Drawing::Rectangle(0, 0, w, h), ImageLockMode::ReadWrite, PixelFormat::Format32bppRgb);

		memcpy(data->Scan0.ToPointer(), ptr, w*h * 4);

		bitmap->UnlockBits(data);
		return bitmap;
	}

	Bitmap^ copy8bppArrayToBitmapArgb(void* ptr, size_t w, size_t h, const byte nByte)
	{
		using namespace System::Drawing::Imaging;
		Bitmap^ bitmap = gcnew Bitmap(w, h, PixelFormat::Format32bppRgb);
		BitmapData^ data = bitmap->LockBits(Drawing::Rectangle(0, 0, w, h), ImageLockMode::ReadWrite, PixelFormat::Format32bppRgb);

		__int8* dest_ptr = (__int8*)data->Scan0.ToPointer();
		__int8* src_ptr = (__int8*)ptr;
		for (size_t i = 0; i < w*h; i++)
		{
			dest_ptr[i * 4 + nByte] = src_ptr[i];
		}

		bitmap->UnlockBits(data);
		return bitmap;
	}

	Bitmap^ copyGrey8bppArrayToBitmapArgb(void* ptr, size_t w, size_t h)
	{
		Bitmap^ bitmap = gcnew Bitmap(w, h, PixelFormat::Format32bppRgb);
		BitmapData^ data = bitmap->LockBits(Drawing::Rectangle(0, 0, w, h), ImageLockMode::ReadWrite, PixelFormat::Format32bppRgb);
		__int8* dest_ptr = (__int8*)data->Scan0.ToPointer();
		__int8* src_ptr = (__int8*)ptr;
		for (size_t i = 0; i < w*h; i++)
		{
			dest_ptr[i * 4 + 0] = src_ptr[i];
			dest_ptr[i * 4 + 1] = src_ptr[i];
			dest_ptr[i * 4 + 2] = src_ptr[i];
		}

		bitmap->UnlockBits(data);
		return bitmap;
	}

	Bitmap^ ResizeImage(Image ^image, int width, int height, Drawing2D::SmoothingMode smoothingMode)
	{
		auto destRect = Drawing::Rectangle(0, 0, width, height);
		auto destImage = gcnew Drawing::Bitmap(width, height);

		destImage->SetResolution(image->HorizontalResolution, image->VerticalResolution);

		Graphics^ graphics = Graphics::FromImage(destImage);
		
		graphics->CompositingMode = Drawing2D::CompositingMode::SourceCopy;
		graphics->CompositingQuality = Drawing2D::CompositingQuality::HighQuality;
		graphics->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
		graphics->SmoothingMode = smoothingMode;
		graphics->PixelOffsetMode = Drawing2D::PixelOffsetMode::HighQuality;

		auto wrapMode = gcnew Imaging::ImageAttributes();
		wrapMode->SetWrapMode(Drawing2D::WrapMode::TileFlipXY);
		graphics->DrawImage(image, destRect, 0, 0, image->Width, image->Height, GraphicsUnit::Pixel, wrapMode);
	
		return destImage;
	}

	

}