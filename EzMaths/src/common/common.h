#pragma once
#include <xmmintrin.h>

static float fastSqrt(float number) 
{

	return *(float*)&_mm_mul_ss(*(__m128*)&number,_mm_rsqrt_ss(*(__m128*)&number));
}