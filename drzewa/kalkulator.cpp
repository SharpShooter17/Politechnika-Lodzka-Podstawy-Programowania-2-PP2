#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum  OP { adding = '+', 
	substraction = '-', 
	multiplication = '*', 
	division = '/'};

struct node_t {
	node_t * l;
	node_t * r;
	bool bOperatorType;
	float value;
	OP op;
};

node_t * node_tree(bool bOperator, float value, OP op, node_t * l, node_t * r)
{
	node_t * node = (node_t*)malloc(sizeof(node_t));
	
	node->bOperatorType = bOperator;
	node->value = value;
	node->op = op;
	node->l = l;
	node->r = r;

	return node;
}

void free_node(node_t * node)
{
	if (node->l != nullptr) free_node(node->l);
	node->l = nullptr;
	if (node->r != nullptr) free_node(node->r);
	node->r = nullptr;

	free(node);
}

float addingf(float a, float b)
{
	return a + b;
}

float substractingf(float a, float b)
{
	return a - b;
}

float multiplicationf(float a, float b)
{
	return a * b;
}

float divisionf(float a, float b)
{
	return a / b;
}

float node_equal(node_t * node)
{
	float l, r;
	if (node->l->bOperatorType == true)
		l = node_equal(node->l);
	
	if (node->r->bOperatorType == true)
		r = node_equal(node->r);

	float (*func)(float a, float b);
	func = nullptr;
	switch (node->op)
	{
	case adding:
		func = addingf;
		break;
	case substraction:
		func = substractingf;
		break;
	case multiplication:
		func = multiplicationf;
		break;
	case division:
		func = divisionf;
		break;
	default:
		break;
	}
	if (node->l->bOperatorType == false && node->r->bOperatorType == false)
		return func(node->l->value, node->r->value);
	else if (node->l->bOperatorType == false && node->r->bOperatorType == true)
		return func(node->l->value, r);
	else
		return func(l, node->r->value);

}

int main()
{
		node_t * node = node_tree(true, 0, multiplication,	
		node_tree(false, 2, adding, nullptr, nullptr), 
																					node_tree(true, 0, adding, 
									node_tree(false, 3, adding, nullptr, nullptr), 
																													node_tree(false, 4, adding, nullptr, nullptr)) );
	
	float x = node_equal(node);

	printf("%f\n", x);

	free_node(node);

	system("pause");

	return 0;
}