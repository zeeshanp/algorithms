//A queue implemented with two stacks;

#include <stdlib.h>
#include <stdio.h>

typedef struct stack* stack_t;
typedef struct queue* queue_t;

struct stack
{
	void** data;
	int count;
	int max;
};

stack_t stack_init()
{
	stack_t s;
	s->count = 0;
	s->max = 8;
	s->data = (void**)malloc(s->max * sizeof(void*));
}

int isEmpty(stack_t s)
{
	return (s->count == 0);
}

void stack_push(stack_t s, void* elem)
{
	if (s->count == s->max)
	{
		s->max += 8;
		s->data = (void**)realloc(s->data, s->max * sizeof(void*));
	}
	
}

void* stack_pop(stack_t s);

struct queue
{
	stack_t inbox;
	stack_t outbox;
};


queue_t queue_init();
void enqueue(queue_t q, void* elem);
void* dequeue(queue_t q);

int main(int argc, char** argv)
{

}