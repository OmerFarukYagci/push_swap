/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 22:48:58 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/26 01:19:51 by omyagci          ###   ########.fr       */
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

static	void	left_side(int *i, t_stack *a, t_operation_counter *op)
{
	while ((*i) > 0)
	{
		ra(a, 1, op);
		(*i)--;
	}
}

static	void	right_side(int *i, t_stack *a, t_operation_counter *op, int s)
{
	while ((*i) < s)
	{
		rra(a, 1, op);
		(*i)++;
	}
}

static void	sort_three(t_stack *a, t_operation_counter *op)
{
	int	first;
	int	second;
	int	third;

	if (!a || a->size != 3)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && first > third)
		ra(a, 1, op);
	else if (second > first && second > third)
		rra(a, 1, op);
	first = a->top->value;
	second = a->top->next->value;
	if (first > second)
		sa(a, 1, op);
}

void	selection_sort(t_stack *a, t_stack *b, t_operation_counter *op)
{
	int	size;
	int	min_node_index;

	if (!a || !b || !op || a->size < 2)
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a, 1, op);
		return ;
	}
	while (a->size > 3)
	{
		min_node_index = get_min_node(a);
		size = a->size;
		if (min_node_index <= size / 2)
			left_side(&min_node_index, a, op);
		else
			right_side(&min_node_index, a, op, size);
		pb(a, b, op);
	}
	sort_three(a, op);
	while (b->size > 0)
		pa(b, a, op);
}
