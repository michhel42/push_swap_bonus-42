/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vihardy <vihardy@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-13 07:18:12 by vihardy           #+#    #+#             */
/*   Updated: 2026-02-13 07:18:12 by vihardy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	square;
	long	next_square;

	if (nb <= 0)
		return (1);
	i = 0;
	while (i * i <= nb)
		i++;
	square = (i - 1) * (i - 1);
	next_square = i * i;
	if (nb - square < next_square - nb)
		return (i - 1);
	return (i);
}
