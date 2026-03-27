/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:35:06 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/27 20:23:11 by omyagci          ###   ########.fr       */
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

typedef struct s_operation_counter
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operation_counter;

int				check_and_add(t_stack *a, int start, int argc, char **argv);
int				print_error(void);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
int				free_split(char **str);
t_number_node	*new_node(int value);
void			add_stack_back(t_stack *stack, t_number_node *new_node);
void			free_all_stack(t_stack *stack);
float			compute_disorder(t_stack *stack);
void			sa(t_stack *a, int printable, t_operation_counter *operate);
void			sb(t_stack *b, int printable, t_operation_counter *operate);
void			ss(t_stack *stack, t_operation_counter *operate);
void			pa(t_stack *b, t_stack *a, t_operation_counter *operate);
void			pb(t_stack *a, t_stack *b, t_operation_counter *operate);
void			ra(t_stack *a, int printable, t_operation_counter *operate);
void			rb(t_stack *b, int printable, t_operation_counter *operate);
void			rr(t_stack *stack, t_operation_counter *operate);
void			rra(t_stack *a, int printable, t_operation_counter *operate);
void			rrb(t_stack *b, int printable, t_operation_counter *operate);
void			rrr(t_stack *stack, t_operation_counter *operate);

#endif
