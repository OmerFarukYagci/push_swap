/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:35:06 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/16 18:22:14 by omyagci          ###   ########.fr       */
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

int				ps_strncmp(const char *s1, const char *s2, size_t n);
int				check_and_add(t_stack *a, int start, int argc, char **argv);
char			**ft_split(char const *s, char c);
int				free_split(char **str);
int				print_error(void);
t_number_node	*new_node(int value);
void			add_stack_back(t_stack *stack, t_number_node *new_node);
void			free_all_stack(t_stack *stack);

#endif
