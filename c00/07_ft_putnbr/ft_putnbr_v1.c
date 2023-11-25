/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:20:21 by mateo             #+#    #+#             */
/*   Updated: 2023/11/24 13:06:33 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	array[11];
	long long	x;
	int		i;

	x = nb;
	i = 0;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		x = -x;
	}
	while (x % 10 != 0 || (x > 0 && x % 10 == 0))
	{
		array[i++] = (x % 10) + 48;
		x = x / 10;
	}
	i--;
	while (i > 0)
	{
		write(1, &array[i], 1);
		i--;
	}
}
