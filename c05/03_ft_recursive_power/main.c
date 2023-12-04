/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:36:39 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:36:39 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	printf("2^2 %d\n", ft_recursive_power(2, 2));
	printf("1^1 %d\n", ft_recursive_power(1, 1));
	printf("3^1 %d\n", ft_recursive_power(3, 1));
	printf("1^0 %d\n", ft_recursive_power(1, 0));
	printf("1^-1 %d\n", ft_recursive_power(1, -1));
	printf("0^0 %d\n", ft_recursive_power(0, 0));
	printf("2500^2500 %d\n", ft_recursive_power(2500, 5));
	return (0);
}
