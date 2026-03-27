/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_third_algortihm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omyagci <omyagci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:28:26 by omyagci           #+#    #+#             */
/*   Updated: 2026/03/27 20:22:28 by omyagci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rrr(t_stack *stack, t_operation_counter *operate)
{
	rra(stack, 0, NULL);
	rrb(stack, 0, NULL);
	write(1, "rrr\n", 4);
	if (operate)
		operate->rrr = operate->rrr + 1;
}
