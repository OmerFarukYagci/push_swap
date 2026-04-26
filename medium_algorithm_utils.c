/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:20:07 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/26 18:29:26 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_i(int *index_array, t_stack *a)
{
	int				i;
	int				new_index;
	t_number_node	*runner_node;
	t_number_node	*temp_node;

	i = 0;
	temp_node = a->top;
	while (temp_node)
	{
		new_index = 0;
		runner_node = a->top;
		while (runner_node)
		{
			if (temp_node->value > runner_node->value)
				new_index++;
			runner_node = runner_node->next;
		}
		index_array[i++] = new_index;
		temp_node = temp_node->next;
	}
}
