#pragma once
#include <stdlib.h>

typedef int type;			//Typ danych C++

struct list_t
{
	struct list_t * next;
	type value;
};

bool sorted(list_t * first);
struct list_t * new_element();
struct list_t * get_element(list_t * first, int N);
void resize(list_t * first, int N);
int size(list_t * first);
void swap_list(list_t * a1, list_t * a1_prev, list_t * a2, list_t * a2_prev);
void remove(list_t * first);