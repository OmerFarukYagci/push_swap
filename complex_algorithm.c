/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:35:08 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/06 16:11:06 by yfirat           ###   ########.fr       */
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

static void	assign_index(t_stack *a)
{
	t_number_node	*curr;
	t_number_node	*comp;
	int				idx;

	curr = a->top;
	while (curr)
	{
		idx = 0;
		comp = a->top;
		while (comp)
		{
			if (curr->value > comp->value)
				idx++;
			comp = comp->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
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
		if (((a->top->index >> i) & 1) == 1)
			ra(a, 1, op);
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
	assign_index(a);
	max_bits = get_max_bits(a->size);
	i = 0;
	while (i < max_bits)
	{
		execute_radix(a, b, op, i);
		i++;
	}
}
