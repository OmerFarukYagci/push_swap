/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_second_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:08:33 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/25 15:10:12 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_stack *a, int printable)
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
		write(1, "ra\n", 4);
}

void	rb(t_stack *b, int printable)
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
		write(1, "rb\n", 4);
}

void	rr(t_stack *stack)
{
	ra(stack, 0);
	rb(stack, 0);
	write(1, "rr\n", 4);
}

void	rra(t_stack *a)
{
	// rra (reverse rotate a): Shift down all elements of stack a by one. The last element becomes the first one.
}