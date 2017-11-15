#include <malloc.h>
#include "lista.h"

bool sorted(list_t * first)
{
	int n = size(first);

	for (int i = 0; i < n-1; i++)
	{
		if (get_element(first, i)->value < get_element(first, i + 1)->value) return false;
	}
	return true;
}

void swap_list(list_t * a1, list_t * a1_prev, list_t * a2, list_t * a2_prev)
{
	if (a1 == NULL || a2 == NULL) return;

	list_t * tmp = a1->next;
	if (a1_prev != NULL) a1_prev->next = a2;
	a1->next = a2->next;
	if (a2_prev != NULL) a2_prev->next = a1;
	a2->next = tmp;
}

struct list_t * new_element()
{
	return (list_t*)malloc(sizeof(list_t));
}

struct list_t * get_element(list_t * first, int N)
{
	if (N < 0) return NULL;

	list_t * res = first;

	for (int i = 0; i < N; i++)
	{
		res = res->next;
	}

	return res;
}

void resize(list_t * first, int N)
{
	list_t * prev = first;

	for (int i = 0; i < N; i++)
	{
		list_t * x = new_element();
		x->value = rand();
		x->next = NULL;
		prev->next = x;
		prev = x;
	}
}

int size(list_t * first)
{
	if (first->next == NULL) return 1;

	int n = 1;

	list_t * prev = first;

	while (true)
	{
		prev = get_element(prev, 1);
		if (prev->next == NULL) return n;
		else n++;
	}
}

void remove(list_t * first)
{
	list_t * next = first;

	while (next != NULL)
	{
		list_t * remove_l = next;
		next = next->next;
		free(remove_l);
	}
}