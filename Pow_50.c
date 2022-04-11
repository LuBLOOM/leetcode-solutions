/* 50. Pow(x, n)

   Statistics
   ==========
   Beats (Time)  - 100% of C submissions
   Beats (Space) - 98.99% of C submissions
 */

#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n)
{
	double res = 1.;
	long e = n;

	if (e < 0) e *= -1;

	while (e) {
		if (e & 1) {
			res = res * x;
		}
		x *= x;
		e >>= 1;
	}

	if (n < 0) return 1/res;
	return res;
}
