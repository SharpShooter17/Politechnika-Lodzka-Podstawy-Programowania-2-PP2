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
	node_t * node1 = node_tree(true, 0, adding, node_tree(false, 100, adding, nullptr, nullptr), 
		node_tree(true, 0, adding, node_tree(false, 200, adding, nullptr, nullptr), 
			node_tree(true, 0, adding, node_tree(false,300, adding, nullptr, nullptr), node_tree(false, 400, adding, nullptr, nullptr)))); //wynik 1000
	
	float x1 = node_equal(node1);
	//(25 + 13 / 4) * 2
	node_t * node2 = node_tree(true, 0, multiplication, node_tree(true, 0, adding, node_tree(false, 25, adding, nullptr, nullptr), node_tree(true, 0, division, node_tree(false, 13, adding, nullptr, nullptr), node_tree(false, 4, adding, nullptr, nullptr)) ), node_tree(false, 2, adding, nullptr, nullptr));
	float x2 = node_equal(node2); //56,5

	node_t * node3 = node_tree(true, 0, multiplication, node_tree(false, -5, adding, nullptr, nullptr), node_tree(true, 0, multiplication, node_tree(true, 0, adding, node_tree(false, 25, adding, nullptr, nullptr), node_tree(true, 0, division, node_tree(false, 13, adding, nullptr, nullptr), node_tree(false, 4, adding, nullptr, nullptr))), node_tree(false, 2, adding, nullptr, nullptr)));
	float x3 = node_equal(node3);

	printf("x1: %f\nx2: %f\nx3: %f\n", x1, x2, x3);

	free_node(node1);
	free_node(node2);
	free_node(node3);

	system("pause");

	return 0;
}