/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_first_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:07:19 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/27 20:37:13 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a, int printable, t_operation_counter *operate)
{
	int	tmp;

	tmp = 0;
	if (a->size < 2)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
	if (printable == 1)
		write(1, "sa\n", 3);
	if (operate)
		operate->sa = operate->sa + 1;
}

void	sb(t_stack *b, int printable, t_operation_counter *operate)
{
	int	tmp;

	tmp = 0;
	if (b->size < 2)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
	if (printable == 1)
		write(1, "sb\n", 3);
	if (operate)
		operate->sb = operate->sb + 1;
}

void	ss(t_stack *a, t_stack *b, t_operation_counter *operate)
{
	sa(a, 0, NULL);
	sb(b, 0, NULL);
	write(1, "ss\n", 3);
	if (operate)
		operate->ss = operate->ss + 1;
}

void	pa(t_stack *b, t_stack *a, t_operation_counter *operate)
{
	t_number_node	*tmp;

	if (b->size < 1)
		return ;
	tmp = b->top->next;
	b->top->next = a->top;
	a->top = b->top;
	a->size = a->size + 1;
	b->top = tmp;
	b->size = b->size - 1;
	write(1, "pa\n", 3);
	if (operate)
		operate->pa = operate->pa + 1;
}

void	pb(t_stack *a, t_stack *b, t_operation_counter *operate)
{
	t_number_node	*tmp;

	if (a->size < 1)
		return ;
	tmp = a->top->next;
	a->top->next = b->top;
	b->top = a->top;
	b->size = b->size + 1;
	a->top = tmp;
	a->size = a->size - 1;
	write(1, "pb\n", 3);
	if (operate)
		operate->pb = operate->pb + 1;
}
