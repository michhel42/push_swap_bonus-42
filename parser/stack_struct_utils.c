/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 04:23:33 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 04:23:33 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

void	add_node_front(t_value **node, t_value *front_node)
{
	t_value	*last;

	if (!*node)
	{
		front_node->next = front_node;
		front_node->prev = front_node;
		*node = front_node;
		return ;
	}
	last = (*node)->prev;
	front_node->prev = (*node)->prev;
	front_node->next = *node;
	(*node)->prev = front_node;
	*node = front_node;
	last->next = front_node;
}

void	add_node_back(t_value **lst, t_value *new)
{
	t_value	*last;

	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return ;
	}
	last = (*lst)->prev;
	new->prev = last;
	new->next = *lst;
	last->next = new;
	(*lst)->prev = new;
}

t_value	*new_node(int value)
{
	t_value	*node;

	node = malloc(sizeof(t_value));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->value = value;
	node->cpx_index = -1;
	node->next = NULL;
	return (node);
}

int	len_struct(t_value *lst)
{
	int		count;
	t_value	*temp;

	if (!lst)
		return (0);
	count = 1;
	if (!lst->next)
		return (count);
	temp = lst;
	while (temp->next && temp->next != lst)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
