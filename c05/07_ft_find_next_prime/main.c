/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:13:00 by mateo             #+#    #+#             */
/*   Updated: 2023/11/08 10:49:28 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	int	i;

	for (i = -2; i < 13; i++)
	{
		printf("next prime after %d: %d\n", i, ft_find_next_prime(i));
	}
	printf("next prime after 6700415: %d\n", ft_find_next_prime(6700415));
	printf("next prime after 6700417: %d\n", ft_find_next_prime(6700417));
	printf("next prime after 6700418: %d\n", ft_find_next_prime(6700418));
	printf("next prime after 2147483646: %d\n", ft_find_next_prime(2147483646));
	printf("next prime after 2147483647: %d\n", ft_find_next_prime(2147483647));
	return (0);
}
