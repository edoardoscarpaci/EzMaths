#ifdef  ASMCHECK
#include "common/common.h"
#include <iostream>
#include <chrono>
#include <cmath>

#define NITER 300
#define TIME  40



void main()
{
	long long c;
	long long worst;
	long long best;
	for (int j = 0; j < TIME; j++) 
	{
		c = 0;
		worst = 0;
		best = 100000000000000000;
		
		for (int i = 0; i < NITER; i++)
		{
			std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
			volatile float z = sqrt(25);
			std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
			long long v = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
			c += v;
			if (v > worst)
				worst = v;
			else if (v < best )
				best = v;

		}

		std::cout << "Run numero: "<<j<< "\nWorst: "<< worst << "\nAverage: " << c/NITER << "\nBest: "<<best<<"\n\n";
	}
	getchar();


}

#endif //  ASMCHECK
