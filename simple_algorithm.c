/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:48:58 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/29 14:07:01 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_min_node(t_stack *a)
{
	t_number_node	*temp;
	int				min_value;
	int				min_node_index;
	int				temp_node_index;

	if (!a || !a->top)
		return (-1);
	temp = a->top;
	min_value = temp->value;
	min_node_index = 0;
	temp_node_index = 0;
	while (temp != NULL)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_node_index = temp_node_index;
		}
		temp = temp->next;
		temp_node_index++;
	}
	return (min_node_index);
}

static	void	left_side(int *min_node_i, t_stack *a, t_operation_counter *opr)
{
	while ((*min_node_i) > 0)
	{
		ra(a, 1, opr);
		(*min_node_i)--;
	}
}

void	selection_sort(t_stack *a, t_stack *b, t_operation_counter *operate)
{
	int	size;
	int	min_node_index;

	while (a->size > 0)
	{
		min_node_index = get_min_node(a);
		size = a->size;
		if (min_node_index <= size / 2)
		{
			left_side(&min_node_index, a, operate);
		}
		else
		{
			while (min_node_index < size)
			{
				rra(a, 1, operate);
				min_node_index++;
			}
		}
		pb(a, b, operate);
	}
	while (b->size > 0)
		pa(b, a, operate);
}
