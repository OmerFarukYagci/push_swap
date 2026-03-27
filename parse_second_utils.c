/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_second_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:08:02 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/27 16:03:47 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

float	compute_disorder(t_stack *stack)
{
	int				mistakes;
	int				total_pairs;
	t_number_node	*i;
	t_number_node	*j;

	if (!stack || !stack->top)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = stack->top;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs += 1;
			if (i->value > j->value)
				mistakes += 1;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / total_pairs);
}
