#include "test.h"
#include <windows.h>
#include <iostream>
#include <intrin.h>
#pragma warning( disable : 4793)

#ifdef _WIN64
unsigned __int64 __forceinline Test::RDTSC() {
	return __rdtsc();
}
#else
unsigned __int64 __forceinline Test::RDTSC() {
	__asm {
		XOR eax, eax
		CPUID
		RDTSC
	}
}
#endif

void Test::calibrate()
{
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
	i64_t1 = RDTSC();
	Sleep(1000);
	i64_t2 = RDTSC();

	cpuq = (double)(i64_t2 - i64_t1) / 1000000000;

}

void Test::start()
{
	i64_t1 = RDTSC();
}

void Test::stop()
{
	i64_t2 = RDTSC();
	i64_t = (unsigned __int64)((double)(i64_t2 - i64_t1) / cpuq);

	if (i64_t >= E3 && i64_t < E6)
	{
		std::cout << i64_t / E3 << " mcs" << " (" << i64_t << " ns)" << std::endl;
	}
	else if (i64_t >= E6 && i64_t < E9)
	{
		std::cout << i64_t / E6 << " ms" << " (" << i64_t << " ns)" << std::endl;
	}
	else if (i64_t > E9)
	{
		std::cout << i64_t / E9 << " s" << " (" << i64_t << " ns)" << std::endl;
	}
	else
	{
		std::cout << i64_t << " ns" << std::endl;
	}
}