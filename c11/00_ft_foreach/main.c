/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:47:31 by mateo             #+#    #+#             */
/*   Updated: 2023/11/13 23:47:31 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_sq(int n)
{
	n = n * n;
	ft_putnbr(n);
	ft_putchar('\n');
}

void	ft_foreach(int *tab, int length, void (*f)(int));

int	main(void)
{
	int	*ptr;
	int	length;
	int	i;

	length = 5;
	ptr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		ptr[i] = i;
		i++;
	}
	ft_foreach(ptr, length, &ft_putnbr);
	ft_putchar('\n');
	ft_foreach(ptr, length, &ft_sq);
	return (0);
}
