/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:28:01 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/01 11:38:31 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static	void	print_string_error(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

static	void	disorder_printer(float disorder)
{
	int	before_point;
	int	after_point;

	
}

void	bench_mod_printer(t_settings *set, t_operation_counter *op,	float dsr)
{
	if (!set || !op)
		return ;
	disorder_printer(dsr);
}
