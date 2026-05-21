/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloubiat <sloubiat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:48:25 by sloubiat          #+#    #+#             */
/*   Updated: 2026/02/17 16:20:14 by sloubiat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pushswap.h"
#include "get_next_line.h"
#include "libft.h"

int	print_ko(t_stack *stack)
{
	write(1, "KO\n", 3);
	free_all(stack);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*buffer;
	t_stack	*stack;

	if (argc == 1)
		return (0);
	stack = parse(argv, argc, 1);
	if (!stack)
		return (0);
	stack->show = 0;
	buffer = get_next_line(0);
	while (buffer)
	{
		if (!parse_action(buffer, stack))
			return (0);
		free(buffer);
		buffer = get_next_line(0);
	}
	if (len_struct(stack->b) > 0)
		return (print_ko(stack));
	if (compute_disorder(stack->a) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(stack);
	return (0);
}
