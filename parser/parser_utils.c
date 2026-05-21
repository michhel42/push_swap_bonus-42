/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 08:14:29 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 08:14:29 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char	*concat_args(char **arg, int len)
{
	char	*s;
	int		i;

	i = 1;
	s = ft_strdup("");
	if (!s)
		return (NULL);
	while (i < len)
	{
		s = ft_strjoin(s, " ");
		if (!s)
			return (NULL);
		s = ft_strjoin(s, arg[i]);
		if (!s)
			return (NULL);
		i++;
	}
	return (s);
}

char	**get_args(char **arg, int len)
{
	char	*concat;
	char	**splited;

	concat = concat_args(arg, len);
	if (!concat)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	splited = ft_split(concat, ' ');
	free(concat);
	return (splited);
}

void	bzero_op(t_operation *total_op)
{
	total_op->sa = 0;
	total_op->sb = 0;
	total_op->ss = 0;
	total_op->pa = 0;
	total_op->pb = 0;
	total_op->ra = 0;
	total_op->rb = 0;
	total_op->rr = 0;
	total_op->rra = 0;
	total_op->rrb = 0;
	total_op->rrr = 0;
	total_op->all = 0;
}
