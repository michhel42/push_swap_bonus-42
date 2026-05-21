/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:28:00 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:28:01 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static void	rotate(t_value **lst)
{
	*lst = (*lst)->next;
}

void	rotate_a(t_stack *stack)
{
	if (!stack->a || stack->a == stack->a->next)
		return ;
	rotate(&stack->a);
	stack->total_op.ra += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	if (!stack->b || stack->b == stack->b->next)
		return ;
	rotate(&stack->b);
	stack->total_op.rb += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_stack *stack)
{
	if (stack->a && stack->a != stack->a->next)
		rotate(&stack->a);
	if (stack->b && stack->b != stack->b->next)
		rotate(&stack->b);
	stack->total_op.rr += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "rr\n", 3);
}
