/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:20:21 by mateo             #+#    #+#             */
/*   Updated: 2023/11/23 11:05:14 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void	ft_putnbr(int nb);

int	main(void)
{
	
	// printf("%d\n", INT_MIN);
	// printf("%d\n", LONG_MIN);
	// printf("%d\n", INT_MAX);
	// printf("%d\n", LONG_MAX);
	ft_putnbr(INT_MIN);
	// write(1, "\n", 1);
	// ft_putnbr(-5);
	// write(1, "\n", 1);
	// ft_putnbr(0);
	// write(1, "\n", 1);
	// ft_putnbr(5);
	// write(1, "\n", 1);
	// ft_putnbr(INT_MAX);
	// write(1, "\n", 1);
	return (0);
}
