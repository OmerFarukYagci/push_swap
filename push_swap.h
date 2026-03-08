/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:35:06 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/07 21:34:55 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_number_node
{
	int						value;
	struct s_number_node	*next;
}							t_number_node;

typedef struct s_stack
{
	t_number_node	*top;
	int				size;
}					t_stack;

typedef struct s_settings
{
	int	strategy;
	int	bench_mode;
}		t_settings;

int		check_number(char *str);
long	ps_atol(const char *nptr);
int		ps_strncmp(const char *s1, const char *s2, size_t n);

#endif