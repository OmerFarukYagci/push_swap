/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:06:02 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/31 20:17:00 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sett_cont(t_settings *settings, int *i, int argc, char **argv)
{
	int	s;
	int	b;

	*i = 1;
	settings->bench_mode = 0;
	settings->strategy = 0;
	while (*i < argc)
	{
		s = settings->strategy;
		b = settings->bench_mode;
		if (ft_strncmp(argv[*i], "--adaptive", 11) == 0 && s == 0)
			settings->strategy = 1;
		else if (ft_strncmp(argv[*i], "--simple", 9) == 0 && s == 0)
			settings->strategy = 2;
		else if (ft_strncmp(argv[*i], "--medium", 9) == 0 && s == 0)
			settings->strategy = 3;
		else if (ft_strncmp(argv[*i], "--complex", 10) == 0 && s == 0)
			settings->strategy = 4;
		else if (ft_strncmp(argv[*i], "--bench", 8) == 0 && b == 0)
			settings->bench_mode = 1;
		else
			break ;
		(*i)++;
	}
}

static void	push_swap_engine(t_stack *a, t_stack *b, t_settings *settings)
{
	t_operation_counter	counter;
	float				disorder;

	if (settings->strategy == 0)
		settings->strategy = 1;
	set_counter(&counter);
	disorder = compute_disorder(a);
	if (disorder == 0.0f)
	{
		if (settings->bench_mode == 1)
			;
		return ;
	}
	if (settings->strategy == 2 || (settings->strategy == 1 && disorder < 0.2f))
		selection_sort(a, b, &counter);
	else if (settings->strategy == 3
		|| (settings->strategy == 1 && disorder >= 0.2f && disorder < 0.5f))
		;
	else if (settings->strategy == 4
		|| (settings->strategy == 1 && disorder >= 0.5f))
		radix_sort(a, b, &counter);
	if (settings->bench_mode == 1)
		;
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack		a;
	t_stack		b;
	t_settings	settings;

	if (argc == 1)
		return (0);
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	sett_cont(&settings, &i, argc, argv);
	if (check_and_add(&a, i, argc, argv) == 0)
	{
		free_all_stack(&a);
		return (print_error());
	}
	push_swap_engine(&a, &b, &settings);
	free_all_stack(&a);
	free_all_stack(&b);
	return (0);
}
