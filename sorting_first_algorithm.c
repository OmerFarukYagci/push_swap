#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	tmp = 0;
	if (a->size < 2)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->prev->value;
	a->top->prev->value = tmp;
}
