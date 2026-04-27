/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:35:08 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/27 14:28:48 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;
	int	max_idx;

	max_idx = size - 1;
	max_bits = 0;
	while ((max_idx >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	execute_radix(t_stack *a, t_stack *b,
				t_operation_counter *op, int i)
{
	int	j;
	int	size;

	j = 0;
	size = a->size;
	while (j < size)
	{
		if (((a->top->value >> i) & 1) == 1)
			ra(a, op);
		else
			pb(a, b, op);
		j++;
	}
	while (b->size > 0)
		pa(b, a, op);
}

void	radix_sort(t_stack *a, t_stack *b, t_operation_counter *op)
{
	int	i;
	int	max_bits;

	if (!a || !b || !op || !a->top || a->size < 2)
		return ;
	if (a->size <= 5)
	{
		selection_sort(a, b, op);
		return ;
	}
	if (!convert_to_index(a))
		return ;
	max_bits = get_max_bits(a->size);
	i = 0;
	while (i < max_bits)
	{
		execute_radix(a, b, op, i);
		i++;
	}
}
