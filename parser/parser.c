/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:27:29 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:35 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static int	parse_stack(char **arg, t_value **stack, int checker)
{
	t_value	*node;

	node = NULL;
	while (*arg)
	{
		if (!((*arg)[0] == '-' && (*arg)[1] == '-') || checker)
		{
			if (!check_nb(*arg, *stack))
				return (free_struct(stack));
			node = new_node(ft_atoi(*arg));
			if (!node)
				return (free_struct(stack));
			add_node_back(stack, node);
		}
		arg++;
	}
	if (*stack != node)
		(*stack)->prev = node;
	return (1);
}

void	start_algo(t_stack *stack)
{
	int	size;

	size = len_struct(stack->a);
	if (stack->adaptive == 1)
	{
		if (size <= 6)
			stack->strategy = SIMPLE;
		else if (stack->disorder < 0.2)
			stack->strategy = SIMPLE;
		else if (stack->disorder < 0.5)
			stack->strategy = MEDIUM;
		else
			stack->strategy = COMPLEX;
	}
	if (stack->strategy == SIMPLE && stack->disorder > 0)
		algo_simple(stack);
	else if (stack->strategy == MEDIUM && stack->disorder > 0)
		algo_medium(stack);
	else if (stack->strategy == COMPLEX && stack->disorder > 0)
		algo_complex(stack);
	if (stack->bench)
		print_bench(stack);
}

static t_stack	*init_struct(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	bzero_op(&stack->total_op);
	stack->bench = 0;
	stack->disorder = 0;
	stack->adaptive = 0;
	stack->show = 1;
	stack->strategy = NONE;
	return (stack);
}

t_stack	*parse(char **arg, int len, int checker)
{
	char			**s;
	t_stack			*stack;

	s = get_args(arg, len);
	if (!s)
		return (0);
	stack = init_struct();
	if (!stack)
	{
		write(2, "Error\n", 6);
		clean_args(s);
		return ((t_stack *)0);
	}
	find_strategy(s, stack);
	if (stack->strategy == ERROR || !parse_stack(s, &stack->a, checker))
	{
		error_clear(s, stack);
		return ((t_stack *) 0);
	}
	clean_args(s);
	return (stack);
}

int	parse_action(char *buffer, t_stack *stack)
{
	if (ft_strncmp(buffer, "pa\n", 3) == 0)
		push_a(stack);
	else if (ft_strncmp(buffer, "pb\n", 3) == 0)
		push_b(stack);
	else if (ft_strncmp(buffer, "rra\n", 4) == 0)
		reverse_rotate_a(stack);
	else if (ft_strncmp(buffer, "rrb\n", 4) == 0)
		reverse_rotate_b(stack);
	else if (ft_strncmp(buffer, "rrr\n", 4) == 0)
		reverse_rotate_rr(stack);
	else if (ft_strncmp(buffer, "ra\n", 3) == 0)
		rotate_a(stack);
	else if (ft_strncmp(buffer, "rb\n", 3) == 0)
		rotate_b(stack);
	else if (ft_strncmp(buffer, "rr\n", 3) == 0)
		rotate_rr(stack);
	else if (ft_strncmp(buffer, "sa\n", 3) == 0)
		swap_a(stack);
	else if (ft_strncmp(buffer, "sb\n", 3) == 0)
		swap_b(stack);
	else if (ft_strncmp(buffer, "ss\n", 3) == 0)
		swap_ss(stack);
	else
		return (print_error(buffer, stack));
	return (1);
}
