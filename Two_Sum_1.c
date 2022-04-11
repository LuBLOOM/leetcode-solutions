/* 1. Two Sum - Easy
   
   Statistics
   ==========
   Beats (Time)  - 80.4% of C submissions
   Beats (Space) - 5.4% of C submissions
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNodePair {
	int key;
	int value;
	struct ListNodePair *next;
};

#define SIZE 10000

struct ListNodePair *arr[SIZE];

void init(void);
int  hashfunc(int);
void insert(int *, int);
int  get(int);
int *twoSums(int *, int, int, int *);

int twoSums(int *nums, int numsSize, int target, char *returnSize)
{
	init();
	int *ans = (int *)malloc(2 * sizeof *ans);
	*returnSize = 2;

	for (int i = 0; i < numsSize; i++) {
		insert(nums, i);
		int need = target - *(nums+i);
		int index = get(need);
		if ((index >= 0) && (index != i)) {
			*(ans+0) = index;
			*(ans+1) = i;
			break;
		}
	}
	return ans;
}

void init(void)
{
	for (int i = 0; i < SIZE; i++) {
		arr[i] = (struct ListNodePair *)malloc(sizeof *arr[i]);
	}
}

int hashfunc(int n)
{
	if (n < 0) n*=-1;
	return n % SIZE;
}

void insert(int *nums, int i)
{
	int n = *(nums+i);
	int h = hashfunc(n);

	struct ListNodePair *copy = arr[h];
	while (copy->next != NULL) {
		copy = copy->next;
	}
	struct ListNodePair *tmp = (struct ListNodePair *)malloc(sizeof *tmp);
	tmp->next = NULL;
	tmp->key = n;
	tmp->value = i;
	copy->next = tmp;
}

int get(int n)
{
	int h = hashfunc(n);
	struct ListNodePair *copy = arr[h];

	while (copy != NULL && copy->key != n) {
		copy = copy->next;
	}

	if (copy == NULL) return -1;
	return copy->value;
}

// or, you this solution:
/* 1. Two Sum - Easy

   Statistics
   ==========
   Beats (Time)  - 8.63% of C submissions
   Beats (Space) - 99.52% of C submissions
 */

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int *ans = (int *)malloc(2 * sizeof *ans);
	*returnSize = 2;
	for (int i = 0; i < numsSize; i++) {
		for (int j = 0; j < numsSize; J++) {
			if (*(nums+i) + *(nums+j) == target && (i != j)) {
				*(ans+0) = i;
				*(ans+1) = j;
				goto end;
			}
		}
	}
 end:
	return ans;
}
