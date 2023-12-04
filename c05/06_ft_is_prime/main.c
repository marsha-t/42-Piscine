/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:48:26 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:48:26 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb);

int	main(void)
{
	int	i;

	for (i = 1; i < 15; i++)
	{
		printf("%d prime?: %d\n", i, ft_is_prime(i));
	}
	printf("-1 prime?: %d\n", ft_is_prime(-1));
	printf("0 prime?: %d\n", ft_is_prime(0));
	printf("1 prime?: %d\n", ft_is_prime(1));
	printf("2147483646 prime?: %d\n", ft_is_prime(2147483646));
	printf("2147483647 prime?: %d\n", ft_is_prime(2147483647));
	return (0);
}
