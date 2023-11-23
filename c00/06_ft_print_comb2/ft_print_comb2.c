/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:41:58 by mateo             #+#    #+#             */
/*   Updated: 2023/11/23 10:44:35 by mateo            ###   ########.fr       */
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
	char	array[2];

	array[0] = -1;
	while (++array[0] < 99)
	{
		array[1] = array[0];
		while (++array[1] < 100)
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
