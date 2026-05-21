/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:27:40 by sloubiat          #+#    #+#             */
/*   Updated: 2026/01/26 17:27:43 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static void	link_nodes(t_value *a, t_value *b)
{
	a->next = b;
	b->prev = a;
}

static void	move_nodes_chain(t_value **src, t_value **dest)
{
	t_value	*last;
	t_value	*next;

	last = (*src)->prev;
	next = (*src)->next;
	add_node_front(dest, *src);
	if (*src == next)
	{
		*src = NULL;
		return ;
	}
	link_nodes(last, next);
	*src = next;
}

void	push_a(t_stack *stack)
{
	if (!stack->b)
		return ;
	move_nodes_chain(&stack->b, &stack->a);
	stack->total_op.pa += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack)
{
	if (!stack->a)
		return ;
	move_nodes_chain(&stack->a, &stack->b);
	stack->total_op.pb += 1;
	stack->total_op.all += 1;
	if (stack->show)
		write(1, "pb\n", 3);
}
