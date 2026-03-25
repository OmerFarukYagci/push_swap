#include "push_swap.h"
#include <unistd.h>

void	rrr(t_stack *stack)
{
	rra(stack, 0);
	rrb(stack, 0);
	write(1, "rrr\n", 5);
}