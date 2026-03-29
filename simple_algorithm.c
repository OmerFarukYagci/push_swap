/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:48:58 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/28 22:48:59 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_minimum_pos(t_stack *stack)
{
	t_number_node	*current;
	int				min_value;
	int				min_pos;
	int				i;

	if (!stack->top)
		return (-1);
	current = stack->top;
	min_value = current->value;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	selection_sort(t_stack *a, t_stack *b, t_operation_counter *operate)
{
	int	min_pos;

	while (a->size > 0)
	{
		min_pos = get_minimum_pos(a);
		if (min_pos <= a->size / 2)
		{
			while (min_pos-- > 0)
				ra(a, 1, operate);
		}
		else
		{
			min_pos = a->size - min_pos;
			while (min_pos-- > 0)
				rra(a, 1, operate);
		}
		pb(a, b, 1, operate);
	}
	while(b->size > 0)
		pa(b, a, operate);
}