#pragma once
#include "../sys/pixbit.h"
#include "../sys/allocator.h"
#include "../sys/test.h"

class imgpart
{
public:
	imgpart(register __int8 *src, const int width, const int height)
	{
		int n = width * height;
		alc::allocator clusters3x3;

		int *dest3x3 = (int*)clusters3x3.init(n * sizeof(int));

		test.calibrate();
		test.start();

		for (int y = 1; y < height-1; y++)
		{
			for (int x = 1; x < width-1; x++)
			{
				register int j = y * width + x;

				dest3x3[j] =  (int)src[j - 1 + width * (-1)] * (+1) + (int)src[j + 0 + width * (-1)] * (+2) + (int)src[j + 1 + width * (-1)] * (+1)
							+ (int)src[j - 1 + width * (+0)] * (+0) + (int)src[j + 0 + width * (+0)] * (+0) + (int)src[j + 1 + width * (+0)] * (+0)
							+ (int)src[j - 1 + width * (+1)] * (-1) + (int)src[j + 0 + width * (+1)] * (-2) + (int)src[j + 1 + width * (+1)] * (-1);
							
							

			}
		}

		test.stop();

		clusters3x3.destroy();
	}
};