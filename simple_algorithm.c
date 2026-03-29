/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:48:58 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/29 13:33:00 by omyagci          ###   ########.fr       */
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
			while (min_node_index > 0)
			{
				ra(a, 1, operate);
				min_node_index--;
			}
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
}
