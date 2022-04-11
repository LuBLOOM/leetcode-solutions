#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNodePair {
	int key;
	int value;
	struct ListNodePair *next;
};

#define SIZE 7

struct ListNodePair *arr[SIZE];

void init(void);
void insert(int, int);
int  hashfunc(int);
int  get(int);

int main(int argc, char **argv)
{
	init();
	insert('I', 1);
	insert('V', 5);
	insert('X', 10);
	insert('L', 50);
	insert('C', 100);
	insert('D', 500);
	insert('M', 1000);

	int ans = 0;
	char *s = "MDCCCLXXXIV";
	size_t size = strlen(s);
	for (int i = 0, c = 0; (c = *(s+i)) != '\0'; ++i) {
		int tmp = get(c);
		int next = 'a';
		while (i <= size - 2 && get((next = *(s+i+1))) > get((c = *(s+i)))) {
			tmp = get(next) - get(c);
			i++;
		}
		ans += tmp;
	}
	printf("%d\n", ans);
	return 0;
}

void init(void)
{
	for (int i = 0; i < SIZE; i++) {
		struct ListNodePair *tmp = (struct ListNodePair *)malloc(sizeof *tmp);
		arr[i] = tmp;
	}
}

int hashfunc(int key)
{
	return key % SIZE;
}

void insert(int key, int value)
{
	int h = hashfunc(key);
	struct ListNodePair *copy = arr[h];
	while (copy->next != NULL) {
		copy = copy->next;
	}
	struct ListNodePair *tmp = (struct ListNodePair *)malloc(sizeof *tmp);
	tmp->key = key;
	tmp->value = value;
	tmp->next = NULL;
	copy->next = tmp;
}

int get(int key)
{
	int h = hashfunc(key);
	struct ListNodePair *copy = arr[h];
	while (copy != NULL && copy->key != key) {
		copy = copy->next;
	}

	if (copy == NULL) return -1;
	return copy->value;
}
