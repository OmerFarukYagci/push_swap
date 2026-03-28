/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_third_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:28:26 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/28 22:56:47 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rrr(t_stack *a, t_stack *b, t_operation_counter *operate)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	rra(a, 0, NULL);
	rrb(b, 0, NULL);
	write(1, "rrr\n", 4);
	if (operate)
	{
		operate->rrr = operate->rrr + 1;
		operate->total_opr = operate->total_opr + 1;
	}
}

void	set_counter(t_operation_counter	*counter)
{
	if (!counter)
		return ;
	counter->sa = 0;
	counter->sb = 0;
	counter->ss = 0;
	counter->pa = 0;
	counter->pb = 0;
	counter->ra = 0;
	counter->rb = 0;
	counter->rr = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->rrr = 0;
	counter->total_opr = 0;
}
