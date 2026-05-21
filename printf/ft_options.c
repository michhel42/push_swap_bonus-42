/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:00:50 by vihardy           #+#    #+#             */
/*   Updated: 2025/11/29 16:25:50 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_options	*init_options(void)
{
	return (gen_list_options(
			"c", handle_char,
			"s", handle_str,
			"p", handle_addr,
			"d", handle_int,
			"i", handle_int,
			"u", handle_unsigned_int,
			"x", handle_hex,
			"X", handle_upper_hex,
			"f", handle_float,
			"y", NULL,
			"%", NULL,
			NULL
		));
}

t_options	*gen_list_options(char *first_opt, ...)
{
	va_list		ap;
	char		*opt;
	t_prt		func;
	t_options	*list;
	t_options	*new_elem;

	list = NULL;
	va_start(ap, first_opt);
	opt = first_opt;
	while (opt)
	{
		func = va_arg(ap, t_prt);
		new_elem = ft_lstnew(opt, func);
		if (!new_elem)
		{
			ft_lstclear(&list);
			va_end(ap);
			return (NULL);
		}
		ft_lstadd_back(&list, new_elem);
		opt = va_arg(ap, char *);
	}
	va_end(ap);
	return (list);
}

t_options	*print_options(const char *str, int *i, t_options *options)
{
	t_options	*tmp;

	tmp = options;
	while (tmp)
	{
		if (find_char(str[*i], tmp->type))
		{
			*i = *i + 1;
			return (tmp);
		}
		tmp = tmp->next;
	}
	*i = *i + 1;
	return (NULL);
}
