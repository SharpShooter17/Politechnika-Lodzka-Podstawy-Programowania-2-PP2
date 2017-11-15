#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t {
	node_t * next;
	node_t * prev;

	unsigned int value;
};

struct list_t {
	node_t * first;
	node_t * last;

	int count;
};

node_t * create_node(int value)
{
	node_t * node = (node_t*)malloc(sizeof(node_t));
	if (node == nullptr)
		return nullptr;
	memset(node, 0, sizeof(node_t));

	node->value = value;
	return node;
}

void new_list(list_t * list)
{
	memset(list, 0, sizeof(list_t));
}

bool push_back(list_t * list, int value)
{
	node_t * node = create_node(value);
	if (node == nullptr)
		return false;

	list->count++;

	if (list->last == nullptr)
	{
		list->first = list->last = node;
		return true;
	}

	list->last->next = node;
	node->prev = list->last;
	list->last = node;

	return true;
}

bool push_front(list_t * list, int value)
{
	node_t * node = create_node(value);
	if (node == nullptr)
		return false;

	list->count++;

	if (list->first == nullptr)
	{
		list->first = list->last = node;
		return true;
	}

	list->first->prev = node;
	node->next = list->first;
	list->first = node;

	return true;
}

void free_nodes(node_t * node)
{
	node_t * p = node->next;
	free(node);

	if( p != nullptr) {
		free_nodes(p);
	}

	return;
}

void destroy_list(list_t * list)
{
	free_nodes(list->first);
}

int get_element(list_t * list, int index)
{
	node_t * it;
	for (it = list->first; index != 0; index--);
	return it->value;
}

int main()
{
	list_t lista;
	new_list(&lista);

	push_front(&lista, 1);
	push_front(&lista, 2);
	push_front(&lista, 3);
	push_front(&lista, 4);
	push_front(&lista, 5);

	push_back(&lista, 6);
	push_back(&lista, 7);
	push_back(&lista, 8);
	push_back(&lista, 9);
	push_back(&lista, 10);

	printf("%d", get_element(&lista, 7));

	destroy_list(&lista);

	system("pause");
	return 0;
}