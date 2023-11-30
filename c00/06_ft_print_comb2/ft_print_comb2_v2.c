/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_v2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:52:50 by mateo             #+#    #+#             */
/*   Updated: 2023/11/27 23:52:52 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nb(int nb)
{
	int	a;
	int	b;

	if (nb > 9)
	{
		a = nb / 10 + 48;
		b = nb % 10 + 48;
		write(1, &a, 1);
		write(1, &b, 1);
	}
	else
	{
		write(1, "0", 1);
		nb += 48;
		write(1, &nb, 1);
	}
}

void	ft_print_comb2(void)
{
	int	array[2];

	array[0] = -1;
	while (++array[0] <= 98)
	{
		array[1] = array[0];
		while (++array[1] <= 99)
		{
			if (array[0] < array[1])
			{
				ft_print_nb(array[0]);
				write(1, " ", 1);
				ft_print_nb(array[1]);
				if (array[0] != 98)
					write(1, ", ", 2);
			}
		}
	}
}
