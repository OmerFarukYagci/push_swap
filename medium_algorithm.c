/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:25:35 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/26 02:13:03 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	convert_to_index(t_stack *a)
{
	int				i;
	int				*index_array;
	t_number_node	*temp_node;

	if (!a || !a->top || a->size <= 0)
		return ;
	index_array = malloc(sizeof(int) * a->size);
	if (!index_array)
		return ;
	calc_i(index_array, a);
	temp_node = a->top;
	i = 0;
	while (temp_node)
	{
		temp_node->value = index_array[i++];
		temp_node = temp_node->next;
	}
	free(index_array);
}

static int	get_max_pos(t_stack *b)
{
	t_number_node	*temp;
	int				max_pos;
	int				max_value;
	int				current_pos;

	if (!b || !b->top)
		return (-1);
	temp = b->top;
	max_value = temp->value;
	max_pos = 0;
	current_pos = 0;
	while (temp)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			max_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	return (max_pos);
}

static void	push_back_a(t_stack *a, t_stack *b, t_operation_counter *op)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = get_max_pos(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos > 0)
			{
				rb(b, 1, op);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < b->size)
			{
				rrb(b, 1, op);
				max_pos++;
			}
		}
		pa(b, a, op);
	}
}

static void	init_vars(t_stack *a, int *i, int *offset)
{
	*i = 0;
	if (a->size <= 100)
		*offset = 15;
	else
		*offset = 35;
	convert_to_index(a);
}

void	chunk_sort(t_stack *a, t_stack *b, t_operation_counter *op)
{
	int	i;
	int	offset;

	if (!a || !b || !op || a->size < 2)
		return ;
	if (a->size <= 5)
	{
		selection_sort(a, b, op);
		return ;
	}
	i = 0;
	init_vars(a, &i, &offset);
	while (a->size > 0)
	{
		if (a->top->value <= i++)
		{
			pb(a, b, op);
			rb(b, 1, op);
		}
		else if (a->top->value <= (i++) + offset)
			pb(a, b, op);
		else
			ra(a, 1, op);
	}
	push_back_a(a, b, op);
}
