/* 69. Sqrt(x)

   Statistics
   ==========
   Beats (Time)  - 100% of C submissions
   Beats (Space) - 57.89% of C submissions
 */

#include <stdio.h>
#include <stdlib.h>

int mySqrt(int x)
{
	double start = 0;
	double end = x;

	while (start <= end) {
		double mid = (start + end)/2.;
		if ((int)(mid * mid) == x) return (int)mid;
		if (mid * mid > x) end = mid;
		if (mid * mid < x) start = mid;
	}

	return -1;
}
