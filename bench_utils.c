/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 19:28:01 by omyagci           #+#    #+#             */
/*   Updated: 2026/04/01 16:13:49 by omyagci          ###   ########.fr       */
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

static void	print_number(int number)
{
	long	ln;
	char	a;

	ln = number;
	if (ln < 0)
	{
		write(2, "-", 1);
		ln = ln * -1;
	}
	if (ln > 9)
		print_number(ln / 10);
	a = (ln % 10) + '0';
	write(2, &a, 1);
}

static	void	disorder_printer(float disorder)
{
	int	before_point;
	int	after_point;

	before_point = (int)(disorder * 100);
	after_point = (int)(disorder * 10000) % 100;
	print_string_error("[bench] disorder: ");
	print_number(before_point);
	print_string_error(".");
	if (after_point < 10)
		print_string_error("0");
	print_number(after_point);
	print_string_error("%\n");
}

static	void	print_operations(t_operation_counter *op)
{
	print_string_error("\n[bench] sa: ");
	print_number(op->sa);
	print_string_error(" sb: ");
	print_number(op->sb);
	print_string_error(" ss: ");
	print_number(op->ss);
	print_string_error(" pa: ");
	print_number(op->pa);
	print_string_error(" pb: ");
	print_number(op->pb);
	print_string_error("\n[bench] ra: ");
	print_number(op->ra);
	print_string_error(" rb: ");
	print_number(op->rb);
	print_string_error(" rr: ");
	print_number(op->rr);
	print_string_error(" rra: ");
	print_number(op->rra);
	print_string_error(" rrb: ");
	print_number(op->rrb);
	print_string_error(" rrr: ");
	print_number(op->rrr);
	print_string_error("\n");
}

void	bench_mod(t_settings *set, t_operation_counter *op,	float dsr)
{
	if (!set || !op)
		return ;
	disorder_printer(dsr);
	print_string_error("[bench] strategy: ");
	if (set->strategy == 1)
	{
		if (dsr < 0.2f)
			print_string_error("Adaptive / O(n²)\n");
		else if (dsr >= 0.2f && dsr < 0.5f)
			print_string_error("Adaptive / O(n√n)\n");
		else
			print_string_error("Adaptive / O(n log n)\n");
	}
	else if (set->strategy == 2)
		print_string_error("Simple / O(n²)\n");
	else if (set->strategy == 3)
		print_string_error("Medium / O(n√n)\n");
	else if (set->strategy == 4)
		print_string_error("Complex / O(n log n)\n");
	print_string_error("[bench] total_ops: ");
	print_number(op->total_opr);
	print_operations(op);
}
