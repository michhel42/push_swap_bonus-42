/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 05:12:31 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 05:12:31 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	algo_simple(t_stack *stack)
{
	t_value	*min_value;
	int		dir;

	while (stack->a)
	{
		min_value = find_min_value(stack->a, &dir);
		while (min_value != stack->a)
		{
			if (dir)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		if (compute_disorder(stack->a) == 0)
			break ;
		push_b(stack);
	}
	while (stack->b)
		push_a(stack);
}
