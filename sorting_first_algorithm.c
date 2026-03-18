#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a, int printable)
{
	int	tmp;

	tmp = 0;
	if (a->size < 2)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	if (printable == 1)
		write(1, "sa\n", 4);
}

void	sb(t_stack *b, int printable)
{
	int	tmp;

	tmp = 0;
	if (b->size < 2)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	write(1, "sb\n", 4);
}

void	ss(t_stack *stack)
{
	sa(stack, 0);
	sb(stack, 0);
	write(1, "ss\n", 4);
}
