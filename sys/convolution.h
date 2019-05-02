#pragma once
#include <windows.h>
#include <math.h>

#include <cstdlib>
#include <immintrin.h>
#include <zmmintrin.h>

#include "pixbit.h"
#include "allocator.h"
#include "imgpart.h"

#define RGBMONO(n)((COLORREF)((BYTE)(n) | ((BYTE)(n) << 8) | ((BYTE)(n) << 16)))
#pragma warning( disable : 4244)

enum thickness
{
	edge1t = 1,
	edge3t = 3,
	edge5t = 5,
	edge7t = 7,
	edge9t = 9,
	edge11t = 11,
	edge13t = 13
};

template <edge2d type> class convolution
{
private:
	int g = 0;
protected:

	void addSemiLine(const BYTE value, const UINT xi, const UINT yi)
	{
		addSemiLine(value, xi, yi, false);
	}

	void addLine(const BYTE value, const UINT xi, const UINT yi)
	{
		addSemiLine(value, xi, yi, false);
		addSemiLine(value, xi, yi, true);
	}

	void addSemiLine(const BYTE value, bool revert180deg, thickness thickness)
	{
		UINT div = 0;
		if (revert180deg) div = type * 2 - 2;

		for (UINT i = 0; i < nCountConvolution; i++)
		{
			UINT radius = type / 2;

			BYTE* mask = (BYTE*)convolutions[i];

			float angle = 3.141592f * (div + i) * 2 / nCountConvolution;

			for (UINT j = 0; j <= radius; j++)
			{
				float X = round(j * cos(angle) - j * sin(angle));

				if (abs(X) > j)
				{
					if (X > 0) X = (float)j; else X = -1 * (float)j;
				}

				float Y = round(j * sin(angle) + j * cos(angle));

				if (abs(Y) > j)
				{
					if (Y > 0) Y = (float)j; else Y = -1 * (float)j;
				}

				UINT x = (UINT)(X + radius);
				UINT y = (UINT)(Y + radius);

				mask[y*type + x] = value;

				if (thickness > thickness::edge1t)
				{
					UINT ty, tx;
					x = x - thickness / 2;
					y = y - thickness / 2;

					for (UINT iy = 0; iy < (UINT)thickness; iy++)
					{
						for (UINT ix = 0; ix < (UINT)thickness; ix++)
						{
							ty = y + iy;
							tx = x + ix;

							if (ty >= type || tx >= type) continue;
							if (ty < 0 || tx < 0) continue;

							mask[ty * type + tx] = value;
						}
					}

				}
			}
		}
	}

	void addSemiLine(const BYTE value, const UINT xi, const UINT yi, bool revert180deg)
	{
		UINT div = 0;
		if (revert180deg) div = type * 2 - 2;

		for (UINT i = 0; i < nCountConvolution; i++)
		{

			UINT radius = type / 2;

			BYTE* mask = (BYTE*)convolutions[i];

			float angle = 3.141592f * (div + i) * 2 / nCountConvolution;

			for (UINT j = 0; j <= radius; j++)
			{
				float X = round(j * cos(angle) - j * sin(angle));

				if (abs(X) > j)
				{
					if (X >= 0) X = (float)j; else X = -1 * (float)j;
				}

				float Y = round(j * sin(angle) + j * cos(angle));

				if (abs(Y) > j)
				{
					if (Y >= 0) Y = (float)j; else Y = -1 * (float)j;
				}

				UINT x = (UINT)(X + xi);
				UINT y = (UINT)(Y + yi);

				if (x >= type || y >= type) continue;

				mask[y*type + x] = value;

			}
		}
	}

	void gradient_x(UINT value_center)
	{
		UINT nt = nCountConvolution / 4;

		for (UINT i = 0; i < 1 * nt; i++)
		{
			BYTE* mask = (BYTE*)convolutions[i];

			for (UINT y = 0; y < type; y++)
			{

				bool find = false;


				for (UINT x = 0; x < type; x++)
				{
					UINT pos = y * type + x;

					if (find == true)
					{

						if (mask[pos] != 0)
							mask[pos] = type - mask[pos] + 1;
					}

					if (mask[pos] == value_center)
					{
						find = true;

					}

				}
			}
		}
	}

	void gradient_y(UINT value_center)
	{
		UINT nt = nCountConvolution / 4;

		for (UINT i = 1 * nt; i < 2 * nt; i++)
		{
			BYTE* mask = (BYTE*)convolutions[i];

			for (UINT x = 0; x < type; x++)
			{

				bool find = false;
				for (UINT y = 0; y < type; y++)
				{
					UINT pos = y * type + x;

					if (find == true)
					{
						if (mask[pos] != 0) mask[pos] = type - mask[pos] + 1;
					}

					if (mask[pos] == value_center)
					{
						find = true;
					}

				}
			}
		}
	}

	void gradient_mx(UINT value_center)
	{
		UINT nt = nCountConvolution / 4;

		for (UINT i = 2 * nt; i < 3 * nt; i++)
		{
			BYTE* mask = (BYTE*)convolutions[i];

			for (UINT y = 0; y < type; y++)
			{

				bool find = false;


				for (int x = type - 1; x >= 0; x--)
				{
					UINT pos = y * type + x;

					if (find == true)
					{

						if (mask[pos] != 0)
							mask[pos] = type - mask[pos] + 1;
					}

					if (mask[pos] == value_center)
					{
						find = true;

					}

				}
			}
		}
	}

	void gradient_my(UINT value_center)
	{
		UINT nt = nCountConvolution / 4;

		for (UINT i = 3 * nt; i < 4 * nt; i++)
		{
			BYTE* mask = (BYTE*)convolutions[i];

			for (UINT x = 0; x < type; x++)
			{

				bool find = false;
				for (int y = type - 1; y >= 0; y--)
				{
					UINT pos = y * type + x;

					if (find == true)
					{
						if (mask[pos] != 0) mask[pos] = type - mask[pos] + 1;
					}

					if (mask[pos] == value_center)
					{
						find = true;
					}

				}
			}
		}
	}

public:
	static const UINT nCountConvolution = type * 4 - 4;
	static const UINT nByteOfConvolution = type * type;
	byte convolutions[nCountConvolution][nByteOfConvolution];

	void memset(BYTE valueFill)
	{
		::memset(convolutions, valueFill, nCountConvolution*nByteOfConvolution);
	}

	void addSemiLine(const BYTE value, thickness thickness)
	{
		addSemiLine(value, false, thickness);
	}

	void addLine(const BYTE value, thickness thickness)
	{
		addSemiLine(value, false, thickness);
		addSemiLine(value, true, thickness);
	}

	void addLineAll(bool gradient = false, bool light = true)
	{
		memset(1);
		int k;
		UINT c = type / 2;
		for (int i = c; i >= 1; i--)
		{
			k = 1 + c - i;// *255 / c;

			addLine(k, c, c - i);
			addLine(k, c, c + i);
			addLine(k, c - i, c);
			addLine(k, c + i, c);
		}

		k = k + 1;
		addLine(k, c, c);
		int y=this->g;
		if (gradient)
		{
			gradient_x(k);
			gradient_y(k);
			gradient_mx(k);
			gradient_my(k);
		}

		if (light)
		{
			for (UINT i = 0; i < nCountConvolution; i++)
			{
				for (UINT j = 0; j < nByteOfConvolution; j++)
				{
					convolutions[i][j] = convolutions[i][j] * (256 / type);
				}
			}
		}
	}

	void addSemiLineAll2(bool light = true)
	{
		g = 0;

		for (int i = type; i >= 1; i = i - 2)
		{
			g++;
			addSemiLine(g, ticThickness(i));

		}

		if (light)
		{
			for (UINT i = 0; i < nCountConvolution; i++)
			{
				for (UINT j = 0; j < nByteOfConvolution; j++)
				{
					convolutions[i][j] = convolutions[i][j] * (256 / type);
				}
			}
		}
	}

	void addLineAll2(bool gradient = false, bool light = true)
	{
		memset(0);
		g = 0;

		for (int i = type; i >= 1; i = i - 2)
		{
			g++;
			addLine(g, thickness(i));

		}

		if (gradient)
		{
			gradient_x(g);
			gradient_y(g);
			gradient_mx(g);
			gradient_my(g);
		}

		if (light)
		{
			for (UINT i = 0; i < nCountConvolution; i++)
			{
				for (UINT j = 0; j < nByteOfConvolution; j++)
				{
					convolutions[i][j] = convolutions[i][j] * (127 / type);
				}
			}
		}
	}

	void paint(HWND hwnd)
	{
		UINT size = nCountConvolution;

		HDC hdc = GetWindowDC(hwnd);

		for (UINT i = 0; i < size; i++)
		{
			byte* mask = convolutions[i];

			int tomove = i * (type + 3);

			for (UINT y = 0; y < type; y++)
			{
				for (UINT x = 0; x < type; x++)
				{
					UINT p = y * type + x;

					SetPixel(hdc, tomove + x, y, RGBMONO(mask[p]));
				}

			}

		}

		ReleaseDC(hwnd, hdc);
	}

	void makemp()
	{
		for (UINT i = 0; i < nCountConvolution; i++)
		{
			for (UINT j = 0; j < nByteOfConvolution; j++)
			{
				convolutions[i][j] = convolutions[i][j] - g;
			}
		}
	}

	void comp(register BYTE* imgpart, int* result)
	{
		register int sum;
		register __int8* conv;

		for (UINT i = 0; i < nCountConvolution; i++)
		{
			sum = 0;
			conv = (__int8*)&convolutions[i];

			for (UINT j = 0; j < nByteOfConvolution; j++)
			{

				sum = sum + conv[j] * imgpart[j];
			}
			result[i] = sum;
		}

	}

	void comp_sse(const BYTE* imgpart, __int16 *result)
	{
		const int div_size = nByteOfConvolution / 8;
		register __m128i cnds8x16i, ipds8x16u, cnds16x8i, ipds16x8i, mul16x8ilo;
		register __int8* conv;
		register __int16 sum;

		for (UINT i = 0; i < nCountConvolution; i++)
		{
			sum = 0;
			conv = (__int8*)&convolutions[i];

			UINT j = 0;
			for (j; j < div_size * 8; j = j + 8)
			{
				cnds8x16i = _mm_load_si128((__m128i*)&conv[j]);
				ipds8x16u = _mm_load_si128((__m128i*)&imgpart[j]);

				cnds16x8i = _mm_cvtepi8_epi16(cnds8x16i);
				ipds16x8i = _mm_cvtepu8_epi16(ipds8x16u);

				mul16x8ilo = _mm_mullo_epi16(cnds16x8i, ipds16x8i);

				mul16x8ilo = _mm_hadd_epi16(mul16x8ilo, mul16x8ilo);
				mul16x8ilo = _mm_hadd_epi16(mul16x8ilo, mul16x8ilo);
				mul16x8ilo = _mm_hadd_epi16(mul16x8ilo, mul16x8ilo);

				sum = sum + mul16x8ilo.m128i_i16[0];
			}

			for (j; j < nByteOfConvolution; j++)
			{
				sum = sum + (__int16)conv[j] * (__int16)imgpart[j];
			}

			result[i] = sum;
		}


	}
};