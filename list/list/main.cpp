#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node_t {
	int value;
	node_t * next;
};

struct node_t * new_element()
{
	node_t * res = (node_t*)malloc(sizeof(node_t));
	res->next = nullptr;
	res->value = 0;
	return res;
}

struct node_t * get_element(node_t * root, int N)
{
	if (N < 0) return NULL;

	node_t * res = root;

	for (int i = 0; i < N; i++)
		res = res->next;

	return res;
}

void resize(node_t * root, int N)
{
	node_t * prev = root;

	for (int i = 0; i < N; i++)
	{
		node_t * x = new_element();
		x->value = (rand() % 20) + 10;
		x->next = NULL;
		prev->next = x;
		prev = x;
	}
}

void remove(node_t * root)
{
	node_t * next = root;

	while (next != NULL)
	{
		node_t * remove_l = next;
		next = next->next;
		free(remove_l);
	}
}

int size(node_t * root)
{
	if (root->next == NULL) return 1;

	int n = 1;

	node_t * prev = root;

	while (true)
	{
		prev = get_element(prev, 1);
		if (prev->next == NULL) return n;
		else n++;
	}
}

void add(node_t * root, int n, node_t * item)
{
	node_t * p = get_element(root, n);
	node_t * q = get_element(p, 1);
	p->next = item;
	item->next = q;
}

void show(const node_t const * root)
{
	if (root == nullptr || root->next == nullptr) return;

	for (const node_t * it = root->next; it != nullptr; it = it->next)
		printf("%d, ", it->value);
}

int main()
{
	node_t * root = new_element();
	resize(root, 10);

	printf("size: %d\n", size(root));
	show(root);

	node_t * nowy = new_element();
	nowy->value = 30;
	add(root, 0, nowy);
	printf("\nsize: %d\n", size(root));
	show(root);

	node_t * nowy1 = new_element();
	nowy1->value = 99;
	add(root, 5, nowy1);
	printf("\nsize: %d\n", size(root));
	show(root);

	remove(root);

	putchar('\n');
	system("pause");
	return 0;
}