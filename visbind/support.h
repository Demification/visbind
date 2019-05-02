#pragma once
#include <windows.h>

namespace support {
	using namespace System;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	Bitmap^ copyArgbArrayToBitmapArgb(void* ptr, size_t w, size_t h);

	Bitmap^ copy8bppArrayToBitmapArgb(void* ptr, size_t w, size_t h, const byte nByte);

	Bitmap^ copyGrey8bppArrayToBitmapArgb(void* ptr, size_t w, size_t h);

	Bitmap^ ResizeImage(Image ^image, int width, int height, Drawing2D::SmoothingMode smoothingMode = Drawing2D::SmoothingMode::HighQuality);

	
}
