/* 633. Sum of Square Numbers

   Statistics
   ==========
   Beats (Time)  - 100% of C submissions
   Beats (Space) - 13.79% of C submissions
 */

#include <stdio.h>
#include <stdlib.h>

bool judgeSquareSum(int c)
{
	for (int i = 2; i * i <= c; i++) {
		int count = 0;
		if (c % i == 0) {
			while (c % i == 0) {
				count++;
				c /= i;
			}
			if (i % 4 == 3 && count % 2 != 0)
				return false;
		}
	}
	return c % 4 != 3;
}
