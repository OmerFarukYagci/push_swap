/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfirat <yfirat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:53:01 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/27 00:53:21 by yfirat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_number_node	*new_node(int value)
{
	t_number_node	*new_node;

	new_node = malloc(sizeof(t_number_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	add_stack_back(t_stack *stack, t_number_node *new_node)
{
	t_number_node	*last;
	int				*size;

	if (!stack || !new_node)
		return ;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		last = stack->top;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
	size = &stack->size;
	(*size)++;
}

void	free_all_stack(t_stack *stack)
{
	t_number_node	*next;
	t_number_node	*temp;

	if (!stack || !stack->top)
		return ;
	temp = stack->top;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
