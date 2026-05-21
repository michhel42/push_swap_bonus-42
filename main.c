/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-12 04:27:22 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-12 04:27:22 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		return (0);
	stack = parse(argv, argc, 0);
	if (!stack)
		return (0);
	stack->disorder = compute_disorder(stack->a);
	start_algo(stack);
	free_all(stack);
	return (0);
}
