/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:27:29 by sloubiat          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:35 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"

static int	check_already_contains(t_value *stack, int number, int size)
{
	while (size > 0)
	{
		if (stack->value == number)
			return (1);
		stack = stack->next;
		size--;
	}
	return (0);
}

int	check_nb(char *nbr, t_value *lst)
{
	int		nb;
	int		size;

	nb = ft_atoi(nbr);
	if (nb == 0)
		if (ft_strncmp(nbr, "0", ft_strlen(nbr))
			&& ft_strncmp(nbr, "-0", ft_strlen(nbr))
			&& ft_strncmp(nbr, "+0", ft_strlen(nbr)))
			return (0);
	if (!lst)
		return (1);
	size = len_struct(lst);
	if (check_already_contains(lst, nb, size))
		return (0);
	return (1);
}
