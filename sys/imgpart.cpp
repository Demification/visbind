#include "imgpart.h"

#include <iostream>
#define RGBMONO(n)((COLORREF)((BYTE)(n) | ((BYTE)(n) << 8) | ((BYTE)(n) << 16)))

void imgpart::init(edge2d edge, edge2d_step step, int width, int height)
{
	this->edge = edge;
	this->step = step;

	this->width = width;
	this->height = height;

	nx = width / step;
	ny = height / step;

	points = new point[nx*ny];

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			int i = y * nx + x;

			points[i].x_offset = x * step - 1;
			points[i].y_offset = y * step - 1;

			//std::cout << points[i].x_offset << " " << points[i].y_offset << std::endl;

		}
	}

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			int i = y * nx + x;

			points[i].x_offset -= edge / 2;
			points[i].y_offset -= edge / 2;

			//std::cout << points[i].x_offset << " " << points[i].y_offset << std::endl;
		}
	}

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			int i = y * nx + x;

			int px = points[i].x_offset;
			int py = points[i].y_offset;

			if ((px < 0) | (py < 0))
			{
				points[i].x_offset = 0;
				points[i].y_offset = 0;
			}
			if ((px + edge >= width) | (py + edge >= height))
			{
				points[i].x_offset = 0;
				points[i].y_offset = 0;
			}


			//std::cout << points[i].x_offset << " " << points[i].y_offset << std::endl;
		}
	}

	buffer.init(nx * ny * edge * edge);

}

void imgpart::preload(byte* ptr)
{
	byte* dest = (byte*)buffer.get0ptr();

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			register int i = y * nx + x;
			register int j = points[i].y_offset * width + points[i].x_offset;

			points[i].ptr = &ptr[j];
		}
	}
}

void imgpart::load()
{
	byte* dest = (byte*)buffer.get0ptr();

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			register int i = y * nx + x;

			register byte* d = &dest[i*edge*edge];
			register byte* s = points[i].ptr;

			for (int iy = 0; iy < edge; iy++)
			{
				for (int ix = 0; ix < edge; ix++)
				{
					d[iy*edge + ix] = s[iy*width + ix];
				}
			}

		}
	}
}

void imgpart::print(HWND hwnd)
{
	byte* src = (byte*)buffer.get0ptr();

	HDC hdc = GetWindowDC(hwnd);

	int stp = 1;

	for (int y = 0; y < ny; y++)
	{
		for (int x = 0; x < nx; x++)
		{
			byte *b = &src[(y * nx + x) * edge*edge];

			for (int iy = 0; iy < edge; iy++)
			{
				for (int ix = 0; ix < edge; ix++)
				{
					SetPixel(hdc, (x*stp) * edge + ix + stp, (y*stp) * edge + iy, RGBMONO(b[iy * edge + ix]));
				}
			}
		}
	}

	ReleaseDC(hwnd, hdc);
}

void imgpart::destroy()
{
	delete points;
	buffer.destroy();
}