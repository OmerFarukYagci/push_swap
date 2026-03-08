/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:06:02 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/08 20:08:42 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	settings.bench_mode = 0;
	settings.strategy = 0;
	i = 1;
	while (i < argc)
	{
		if (ps_strncmp(argv[i], "--adaptive", 11) == 0)
			settings.strategy = 0;
		else if (ps_strncmp(argv[i], "--simple", 9) == 0)
			settings.strategy = 1;
		else if (ps_strncmp(argv[i], "--medium", 9) == 0)
			settings.strategy = 2;
		else if (ps_strncmp(argv[i], "--complex", 10) == 0)
			settings.strategy = 3;
		else if (ps_strncmp(argv[i], "--bench", 8) == 0)
			settings.bench_mode = 1;
		else
			break ;
		i++;
	}
}
