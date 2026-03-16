/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_first_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:47 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/16 18:45:08 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ps_atol(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	check_duplicate(t_stack *a, int number)
{
	t_number_node	*temp_node;

	if (a == NULL || a->top == NULL)
		return (0);
	temp_node = a->top;
	while (temp_node != NULL)
	{
		if (temp_node->value == number)
			return (1);
		temp_node = temp_node->next;
	}
	return (0);
}

int	check_and_add(t_stack *a, int start, int argc, char **argv)
{
	long			temp;
	t_number_node	*node;
	char			**split;
	int				i;

	while (start < argc)
	{
		split = ft_split(argv[start], ' ');
		if (!split || !split[0])
			return (free_split(split));
		i = 0;
		while (split[i])
		{
			if (check_number(split[i]) == 0)
				return (free_split(split));
			temp = ps_atol(split[i]);
			if (temp > 2147483647 || temp < -2147483648)
				return (free_split(split));
			if (check_duplicate(a, (int)temp) == 1)
				return (free_split(split));
			node = new_node(temp);
			if (node == NULL)
				return (free_split(split));
			add_stack_back(a, node);
			i++;
		}
		free_split(split);
		start++;
	}
	return (1);
}
