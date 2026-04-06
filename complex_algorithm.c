/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:35:08 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/06 14:42:18 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max_bits;
	int	max_value;

	if (!stack || !stack->top)
		return (0);
	max_value = stack->size -1;
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	assign_index(t_stack *a)
{
	t_number_node	*current;
	t_number_node	*compare;
	int				index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->value = index;
		current = current->next;
	}
}

void	radix_sort(t_stack *a, t_stack *b, t_operation_counter *op)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (!a || !b || !op || !a->top)
		return ;
	assign_index(a);
	size = a->size;
	max_bits = get_max_bits(a);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((a->top->value >> i) & 1) == 1)
				ra(a, 1, op);
			else
				pb(a, b, op);
		}
		while (b->size > 0)
			pa(b, a, op);
	}
}
