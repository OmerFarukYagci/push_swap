#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a)
{
	int	tmp;

	tmp = 0;
	if (a->size < 2)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = tmp;
	write(1, "sa\n", 4);
}

void	sb(t_stack *b)
{
	int	tmp;

	tmp = 0;
	if (b->size < 2)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->prev->value;
	b->top->prev->value = tmp;
	write(1, "sb\n", 4);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	write(1, "ss\n", 4);
}
