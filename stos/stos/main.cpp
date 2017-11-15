#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct stack_t {
	unsigned int idx;
	unsigned int top;
	int * stack;
};

void stack_free(stack_t * s);

stack_t * new_stack(unsigned int initial_capacity)
{
	stack_t * res = (stack_t*)malloc(sizeof(stack_t));
	
	if (res == nullptr) {
		exit(1);
	}

	res->stack = (int*)malloc(initial_capacity *sizeof(int));
	if (res->stack == nullptr)
	{
		free(res);
		exit(1);
	}

	res->idx = 0;
	res->top = initial_capacity;

	return res;
}

void push(stack_t * s, int value)
{
	if ((s->idx) == s->top)
	{
		s->top++;
		int * tmp = (int*)realloc(s->stack, s->top*sizeof(int));
		if (tmp == nullptr)
		{
			stack_free(s);
			exit(-1);
		}
		s->stack = tmp;
	}

	s->stack[(s->idx)++] = value;
}

int pop(stack_t * s)
{
	return s->stack[--s->idx];
}

bool try_push(stack_t * s, int value)
{
	if (s->idx == s->top) return true;
	push(s, value);
	return false;
}

bool try_pop(stack_t * s, int * var)
{
	if (s->idx == 0) return false;
	*var = pop(s);
	return true;
}

bool empty(const stack_t * s)
{
	return s->idx == 0 ? true : false;
}

void stack_free(stack_t * s)
{
	if (s->stack != nullptr) {
		free(s->stack);
		s->stack = nullptr;
	}
	free(s);
	s = nullptr;
}

void remove_elements(stack_t * s)
{
	s->idx = 0;
}

int save_stack_to(stack_t * s, const char * file_name)
{
	FILE * file = fopen(file_name, "wb");
	if (file == nullptr) return -1;

	fwrite(s, sizeof(unsigned int), 2, file);
	fwrite(s->stack, sizeof(int), s->idx, file);

	fclose(file);
	return 0;
}

int read_stack_from(stack_t ** s, const char * file_name)
{
	FILE * file = fopen(file_name, "rb");
	if (file == nullptr) return -1;

	int stack_size, stack_idx;

	fread(&stack_idx, sizeof(unsigned int), 1, file);
	fread(&stack_size, sizeof(unsigned int), 1, file);
	*s = new_stack(stack_size);
	s[0]->idx = stack_idx;
	
	fread(s[0]->stack, sizeof(int), s[0]->idx, file);

	fclose(file);
	return 0;
}

void show_stack(const stack_t const * s)
{
	for (int i = 0; i < s->idx; i++)
		printf("%d, ", s->stack[i]);
}

int main()
{
	stack_t * stack = new_stack(1);

	for (int i = 0; i < 500; i++)
		push(stack, i);

	for (int i = 0; i < 500; i++)
		printf("%d, ", pop(stack));

	stack_free(stack);

	system("pause");
	return 0;
}