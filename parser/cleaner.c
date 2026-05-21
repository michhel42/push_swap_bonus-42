/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:27:29 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:35 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>
#include <unistd.h>

void	clean_args(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

void	error_clear(char **arg, t_stack	*stack)
{
	clean_args(arg);
	free(stack);
	write(2, "Error\n", 6);
}

void	free_all(t_stack *stack)
{
	free_struct(&stack->a);
	free_struct(&stack->b);
	free(stack);
}

int	free_struct(t_value **lst)
{
	t_value	*tmp;
	int		size;

	if (!lst || !*lst)
		return (0);
	size = len_struct(*lst);
	while (size > 0)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
		size--;
	}
	*lst = NULL;
	return (0);
}

int	print_error(char *buffer, t_stack *stack)
{
	write(2, "Error\n", 6);
	free(buffer);
	free_all(stack);
	return (0);
}
