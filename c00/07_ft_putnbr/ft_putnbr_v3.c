/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:20:21 by mateo             #+#    #+#             */
/*   Updated: 2023/11/23 10:56:42 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Approach 3 - using recursion and making it universal
void	ft_putnbr(int nb)
{
	char str[11] = "0123456789"; // won't pass norminette

	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &str[nb % 10], 1);
}