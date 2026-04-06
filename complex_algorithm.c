/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abusivesnake <abusivesnake@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:35:08 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/06 14:23:24 by abusivesnak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	t_number_node	*current;
	int				max_value;
	int				max_bits;

	if (!stack || !stack->top)
		return (0);
	max_value = stack->top->value;
	current = stack->top->next;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b, t_operation_counter *op)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	if (!a || !b || !op || !a->top)
		return ;
	size = a->size;
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->value >> i) & 1) == 1)
				ra(a, 1, op);
			else
				pb (a, b, op);
			j++;
		}
		while (b->size > 0)
			pa(b, a, op);
		i++;
	}
}
