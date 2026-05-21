/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:27:50 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:27:52 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static void	rrotate(t_value **lst)
{
	*lst = (*lst)->prev;
}

void	reverse_rotate_a(t_stack *stack)
{
	if (!stack->a || stack->a == stack->a->next)
		return ;
	rrotate(&stack->a);
	stack->total_op.rra += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	if (!stack->b || stack->b == stack->b->next)
		return ;
	rrotate(&stack->b);
	stack->total_op.rrb += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rr(t_stack *stack)
{
	if (stack->a && stack->a != stack->a->next)
		rrotate(&stack->a);
	if (stack->b && stack->b != stack->b->next)
		rrotate(&stack->b);
	stack->total_op.rrr += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "rrr\n", 4);
}
