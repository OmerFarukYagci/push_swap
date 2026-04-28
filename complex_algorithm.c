/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:35:08 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/28 19:12:13 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int size)
{
	int	maximum_bits;
	int	max_idx;

	max_idx = size - 1;
	maximum_bits = 0;
	while ((max_idx >> maximum_bits) != 0)
		maximum_bits++;
	return (maximum_bits);
}

static void	back_a(t_stack *a, t_stack *b, t_operation_counter *op)
{
	while (b->size > 0)
		pa(b, a, op);
}

static void	radix_iteration(t_stack *a, t_stack *b,
				t_operation_counter *op, int bit_index)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (((a->top->value >> bit_index) & 1) == 1)
			ra(a, op);
		else
			pb(a, b, op);
		i++;
	}
	back_a(a, b, op);
}

void	radix_sort(t_stack *a, t_stack *b, t_operation_counter *op)
{
	int	bit_index;
	int	maximum_bits;

	if (!a || !b || !op || !a->top || a->size < 2)
		return ;
	if (a->size <= 5)
	{
		selection_sort(a, b, op);
		return ;
	}
	if (!convert_to_index(a))
		return ;
	maximum_bits = count_bits(a->size);
	bit_index = 0;
	while (bit_index < maximum_bits)
	{
		radix_iteration(a, b, op, bit_index);
		bit_index++;
	}
}
