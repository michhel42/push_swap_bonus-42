/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:52:17 by vihardy           #+#    #+#             */
/*   Updated: 2025/12/20 14:24:30 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_options	*ft_lstnew(char *opt, t_prt prt)
{
	t_options	*node;

	node = malloc(sizeof(t_options));
	if (!node)
		return (NULL);
	node->type = opt;
	node->prt = prt;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_options **lst, t_options *new)
{
	t_options	*temp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	ft_lstclear(t_options **lst)
{
	t_options	*tmp;

	if (!lst || !*lst)
		return (-1);
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	return (-1);
}
