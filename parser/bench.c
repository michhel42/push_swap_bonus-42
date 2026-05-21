/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-13 09:43:58 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-13 09:43:58 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf.h"
#include "libft.h"

static char	*algo_str(t_stack *stack)
{
	if (stack->adaptive)
		return ("Adaptive");
	else if (stack->strategy == SIMPLE)
		return ("Simple");
	else if (stack->strategy == MEDIUM)
		return ("Medium");
	else if (stack->strategy == COMPLEX)
		return ("Complex");
	else
		return ("NONE");
}

static char	*math_str(t_strategy strat)
{
	if (strat == SIMPLE)
		return ("O(n²)");
	else if (strat == MEDIUM)
		return ("O(n√n)");
	else if (strat == COMPLEX)
		return ("O(n log n)");
	else
		return ("NONE");
}

void	print_bench(t_stack *stack)
{
	t_operation	ops;

	ops = stack->total_op;
	ft_printf(
		"[bench] disorder: %f%%\n"
		"[bench] strategy: %s / %s\n"
		"[bench] total_ops: %d\n"
		"[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb  %d\n"
		"[bench] ra:  %d  rb:  %d  rr:  %d  rra: %d  rrb %d  rrr: %d\n",
		stack->disorder * 100, algo_str(stack), math_str(stack->strategy),
		ops.all, ops.sa, ops.sb, ops.ss, ops.pa, ops.pb,
		ops.ra, ops.rb, ops.rr, ops.rra, ops.rrb, ops.rrr);
}
