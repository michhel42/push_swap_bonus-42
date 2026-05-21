/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 08:09:02 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 08:09:02 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include "ft_printf.h"

static int	get_index(int value, t_bucket bucket)
{
	int	index;

	index = (value - bucket.min->value) / bucket.size;
	if (index < 0)
		index = 0;
	if (index >= bucket.nb)
		index = bucket.nb - 1;
	return (index);
}

static int	find_position_in_bucket(t_stack *stack, t_bucket bucket)
{
	t_value	*tmp;
	int		pos;
	int		len;

	tmp = stack->a;
	pos = 0;
	len = len_struct(stack->a);
	while (pos < len)
	{
		if (get_index(tmp->value, bucket) == bucket.current)
			return (pos);
		tmp = tmp->next;
		pos++;
	}
	return (-1);
}

static void	push_bucket(t_stack *stack, t_bucket bucket)
{
	int	pos;
	int	len;

	pos = find_position_in_bucket(stack, bucket);
	len = len_struct(stack->a);
	while (pos != -1)
	{
		len = len_struct(stack->a);
		if (pos <= len / 2)
		{
			while (pos-- > 0)
				rotate_a(stack);
		}
		else
		{
			pos = len - pos;
			while (pos-- > 0)
				reverse_rotate_a(stack);
		}
		push_b(stack);
		pos = find_position_in_bucket(stack, bucket);
	}
}

static void	bucket_repartition(t_stack *stack, t_bucket bucket)
{
	bucket.current = 0;
	while (bucket.current < bucket.nb)
	{
		push_bucket(stack, bucket);
		bucket.current++;
	}
}

void	algo_medium(t_stack *stack)
{
	t_bucket	bucket;
	t_value		*max;
	int			dir;
	int			total;

	total = len_struct(stack->a);
	bucket.min = find_min_value(stack->a, &dir);
	bucket.max = find_max_value(stack->a, &dir);
	bucket.size = (bucket.max->value - bucket.min->value);
	bucket.nb = ft_sqrt(total);
	bucket.size = bucket.size / bucket.nb + 1;
	bucket_repartition(stack, bucket);
	while (stack->b)
	{
		max = find_max_value(stack->b, &dir);
		while (max != stack->b)
		{
			if (dir)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
		push_a(stack);
	}
}
