/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:28:10 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:28:11 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf.h"
#include <unistd.h>

static void	swap_addr(t_value **lst)
{
	t_value	*value_a;
	t_value	*value_b;
	t_value	*value_c;
	int		size;

	size = len_struct(*lst);
	value_a = *lst;
	value_b = (*lst)->next;
	value_c = (*lst)->prev;
	value_a->next = value_b->next;
	value_b->prev = value_a->prev;
	value_b->next = value_a;
	value_a->prev = value_b;
	*lst = value_b;
	if (size > 2)
		value_c->next = *lst;
	else
		value_a->next = *lst;
}

void	swap_a(t_stack *stack)
{
	if (!stack->a || stack->a == stack->a->next)
		return ;
	swap_addr(&stack->a);
	stack->total_op.sa += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	if (!stack->b || stack->b == stack->b->next)
		return ;
	swap_addr(&stack->b);
	stack->total_op.sb += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "sb\n", 3);
}

void	swap_ss(t_stack *stack)
{
	if (stack->b && stack->b != stack->b->next)
		swap_addr(&stack->b);
	if (stack->a && stack->a != stack->a->next)
		swap_addr(&stack->a);
	stack->total_op.ss += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "ss\n", 3);
}
