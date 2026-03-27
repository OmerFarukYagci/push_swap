/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_second_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:08:33 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/27 20:40:35 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_stack *a, int printable, t_operation_counter *operate)
{
	t_number_node	*first;
	t_number_node	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	first->next = NULL;
	last = a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	if (printable == 1)
		write(1, "ra\n", 3);
	if (operate)
		operate->ra = operate->ra + 1;
}

void	rb(t_stack *b, int printable, t_operation_counter *operate)
{
	t_number_node	*first;
	t_number_node	*last;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	b->top = first->next;
	first->next = NULL;
	last = b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	if (printable == 1)
		write(1, "rb\n", 3);
	if (operate)
		operate->rb = operate->rb + 1;
}

void	rr(t_stack *a, t_stack *b, t_operation_counter *operate)
{
	ra(a, 0, NULL);
	rb(b, 0, NULL);
	write(1, "rr\n", 3);
	if (operate)
		operate->rr = operate->rr + 1;
}

void	rra(t_stack *a, int printable, t_operation_counter *operate)
{
	t_number_node	*last;
	t_number_node	*prev;

	if (!a || a->size < 2)
		return ;
	last = a->top;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	if (printable == 1)
		write(1, "rra\n", 4);
	if (operate)
		operate->rra = operate->rra + 1;
}

void	rrb(t_stack *b, int printable, t_operation_counter *operate)
{
	t_number_node	*last;
	t_number_node	*prev;

	if (!b || b->size < 2)
		return ;
	last = b->top;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->top;
	b->top = last;
	if (printable == 1)
		write(1, "rrb\n", 4);
	if (operate)
		operate->rrb = operate->rrb + 1;
}
