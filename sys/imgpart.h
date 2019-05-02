#pragma once
#include <windows.h>
#include "allocator.h"

enum edge2d
{
	edge1x1 = 1,
	edge3x3 = 3,
	edge5x5 = 5,
	edge7x7 = 7,
	edge9x9 = 9,
	edge11x11 = 11,
	edge13x13 = 13

};

enum edge2d_step
{
	x1 = 1, 
	x2 = 2,
	x3 = 3,
	x4 = 4,
	x5 = 5,
	x6 = 6,
	x7 = 7

};

class imgpart
{
public:
	edge2d edge;
	edge2d_step step;
	alc::allocator buffer;

	int width; 
	int height;

	int nx;
	int ny;

	struct point { int x_offset; int y_offset; byte* ptr; } *points;

	void init(edge2d edge, edge2d_step step, int width, int height);

	void preload(byte* ptr);

	void load();

	void print(HWND hwnd);
	
	void destroy();
};
