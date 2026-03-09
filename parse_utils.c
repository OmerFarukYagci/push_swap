/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:51:47 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/09 15:39:58 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_strncmp(const char *s1, const char *s2, size_t n)
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

int	check_number(char *str)
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

long	ps_atol(const char *nptr)
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

int	check_duplicate(t_stack *a, int number)
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
	int		i;
	long	temp;

	i = start;
	while (i < argc)
	{
		if (check_number(argv[i]) == 0)
			return (0);
		temp = ps_atol(argv[i]);
		if (temp > 2147483647 || temp < -2147483648)
			return (0);
		if (check_duplicate(a, argv[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}
