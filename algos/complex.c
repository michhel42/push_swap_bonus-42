/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 08:40:04 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 08:40:04 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

static int	find_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	gen_cpx_idx(t_value *stack, int size)
{
	t_value	*min;
	t_value	*temp;
	int		len;
	int		i;

	len = 0;
	while (len < size)
	{
		min = NULL;
		temp = stack;
		i = 0;
		while (i < size)
		{
			if (temp->cpx_index == -1 && (!min || temp->value < min->value))
				min = temp;
			temp = temp->next;
			i++;
		}
		min->cpx_index = len;
		len++;
	}
}

void	algo_complex(t_stack *stack)
{
	int	size;
	int	bits_max;
	int	bit;
	int	i;

	size = len_struct(stack->a);
	gen_cpx_idx(stack->a, size);
	bits_max = find_max_bits(size);
	bit = 0;
	while (bit < bits_max)
	{
		i = 0;
		while (i < size)
		{
			if (((stack->a->cpx_index >> bit) & 1) == 0)
				push_b(stack);
			else
				rotate_a(stack);
			i++;
		}
		while (stack->b)
			push_a(stack);
		bit++;
	}
}
