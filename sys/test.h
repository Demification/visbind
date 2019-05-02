#pragma once

static class Test
{
private:
	const unsigned int E3 = 1000;
	const unsigned int E6 = 1000000;
	const unsigned int E9 = 1000000000;
	double cpuq = 0;
	unsigned __int64 i64_t, i64_t1, i64_t2;
public:
	unsigned __int64 t;
	unsigned __int64 __forceinline RDTSC();

	void calibrate();
	void start();
	void stop();

} test;

