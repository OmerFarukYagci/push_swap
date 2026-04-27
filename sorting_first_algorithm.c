/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_first_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:07:19 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/27 13:09:01 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a, t_operation_counter *operate)
{
	int	tmp;

	if (!a || a->size < 2)
		return ;
	tmp = 0;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	write(1, "sa\n", 3);
	if (operate)
	{
		operate->sa = operate->sa + 1;
		operate->total_opr = operate->total_opr + 1;
	}
}

void	pa(t_stack *b, t_stack *a, t_operation_counter *operate)
{
	t_number_node	*tmp;

	if (!b || !a || b->size < 1)
		return ;
	tmp = b->top->next;
	b->top->next = a->top;
	a->top = b->top;
	a->size = a->size + 1;
	b->top = tmp;
	b->size = b->size - 1;
	write(1, "pa\n", 3);
	if (operate)
	{
		operate->pa = operate->pa + 1;
		operate->total_opr = operate->total_opr + 1;
	}
}

void	pb(t_stack *a, t_stack *b, t_operation_counter *operate)
{
	t_number_node	*tmp;

	if (!a || !b || a->size < 1)
		return ;
	tmp = a->top->next;
	a->top->next = b->top;
	b->top = a->top;
	b->size = b->size + 1;
	a->top = tmp;
	a->size = a->size - 1;
	write(1, "pb\n", 3);
	if (operate)
	{
		operate->pb = operate->pb + 1;
		operate->total_opr = operate->total_opr + 1;
	}
}
