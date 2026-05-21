/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 08:10:21 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 08:10:21 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_value	*find_min_value(t_value *lst, int *dir)
{
	t_value	*temp;
	t_value	*min;
	int		i;
	int		i_min;

	i = 1;
	i_min = 0;
	min = lst;
	temp = min->next;
	while (temp != lst)
	{
		if (temp->value < min->value)
		{
			i_min = i;
			min = temp;
		}
		i++;
		temp = temp->next;
	}
	*dir = 1;
	if (i_min > (len_struct(lst) / 2))
		*dir = 0;
	return (min);
}

t_value	*find_max_value(t_value *lst, int *dir)
{
	t_value	*temp;
	t_value	*max;
	int		i;
	int		i_max;

	i = 1;
	i_max = 0;
	max = lst;
	temp = max->next;
	while (temp != lst)
	{
		if (temp->value > max->value)
		{
			i_max = i;
			max = temp;
		}
		temp = temp->next;
		i++;
	}
	*dir = 1;
	if (i_max > (len_struct(lst) / 2))
		*dir = 0;
	return (max);
}
