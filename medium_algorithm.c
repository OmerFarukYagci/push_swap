/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:25:35 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/03 06:34:07 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static	void	convert_to_index(t_stack *a)
{
	int				i;
	int				new_index;
	int				*index_array;
	t_number_node	*temp_node;
	t_number_node	*runner_node;

	if (!a || !a->top || a->size <= 0)
		return ;
	index_array = malloc(sizeof(int) * a->size);
	if (!index_array)
		return ;
	temp_node = a->top;
	i = 0;
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
	temp_node = a->top;
	i = 0;
	while (temp_node)
	{
		temp_node->value = index_array[i++];
		temp_node = temp_node->next;
	}
	free(index_array);
}

static	void	create_chunks(t_stack *a, t_stack *b, t_operation_counter *op)
{
	// Buradaki kodlar yeniden incelenerek yazılacak.
}

void	chunk_sort(t_stack *a, t_stack *b, t_operation_counter *op)
{
	if (!a || !b || !op || a->size < 2)
		return ;
	convert_to_index(a);
	create_chunks(a, b, op);
}
