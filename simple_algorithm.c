/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:48:58 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/29 11:13:44 by omyagci          ###   ########.fr       */
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
