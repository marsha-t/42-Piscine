/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:22:56 by mateo             #+#    #+#             */
/*   Updated: 2023/11/23 10:52:15 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_is_negative(int n);

int	main(void)
{
	
	ft_is_negative(INT_MAX);
	write(1, "\n", 1);
	ft_is_negative(5);
	write(1, "\n", 1);
	ft_is_negative(0);
	write(1, "\n", 1);
	ft_is_negative(-5);
	write(1, "\n", 1);
	ft_is_negative(INT_MIN);
	write(1, "\n", 1);
	return (0);
}
