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

static t_strategy	verif_strategy(char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcmp(arg, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcmp(arg, "--complex") == 0)
		return (COMPLEX);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (ADAPTIVE);
	return (NONE);
}

static int	is_strategy(t_stack *stack, char *arg)
{
	t_strategy	t;

	t = verif_strategy(arg);
	if (t != NONE)
	{
		if (stack->strategy == NONE)
		{
			stack->strategy = t;
			if (t == ADAPTIVE)
				stack->adaptive = 1;
		}
		else
			stack->strategy = ERROR;
		return (1);
	}
	return (0);
}

void	find_strategy(char **arg, t_stack *stack)
{
	while (*arg)
	{
		if (ft_strcmp(*arg, "--bench") == 0)
		{
			if (stack->bench == 0)
				stack->bench = 1;
			else
				stack->strategy = ERROR;
		}
		else if (!is_strategy(stack, *arg)
			&& (*arg)[0] == '-'
			&& (*arg)[1] == '-')
			stack->strategy = ERROR;
		if (stack->strategy == ERROR)
			return ;
		arg++;
	}
	if (stack->strategy == NONE)
		stack->adaptive = 1;
}

static void	find_mist_pairs(t_value *lst, int *mist, int *pairs, int size)
{
	int		j;
	t_value	*temp;

	j = 0;
	temp = lst->next;
	while (j < size)
	{
		(*pairs)++;
		if (lst->value > temp->value)
			(*mist)++;
		temp = temp->next;
		j++;
	}
}

float	compute_disorder(t_value *stack)
{
	int		mistakes;
	int		total_pairs;
	int		size;

	mistakes = 0;
	total_pairs = 0;
	size = len_struct(stack) - 1;
	if (size <= 0)
		return (0);
	while (size > 0)
	{
		find_mist_pairs(stack, &mistakes, &total_pairs, size);
		stack = stack->next;
		size--;
	}
	return ((float)mistakes / (float)total_pairs);
}
