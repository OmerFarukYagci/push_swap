/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_third_algortihm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:28:26 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/27 21:04:51 by omyagci          ###   ########.fr       */
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
		operate->rrr = operate->rrr + 1;
}
