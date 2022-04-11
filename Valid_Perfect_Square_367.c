/* 367. Valid Perfect Square

   Statistics
   ==========
   Beats (Time)  - 100% of C submissions
   Beats (Space) - 58.41% of C submissions
 */


#include <stdio.h>
#include <stdlib.h>

bool isPerfectSquare(int num)
{
	unsigned long start = 0;
	unsigned long end = num;

	while (start <= end) {
		unsigned long mid = (start + end)/2;
		if (mid * mid == num) return true;
		if (mid * mid > num) end = mid - 1;
		if (mid * mid < num) start = mid + 1;
	}
	
	return false;
}
