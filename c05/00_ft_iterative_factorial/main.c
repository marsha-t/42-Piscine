/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:35:24 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:35:24 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	printf("3!: %d\n", ft_iterative_factorial(3));
	printf("2!: %d\n", ft_iterative_factorial(2));
	printf("1!: %d\n", ft_iterative_factorial(1));
	printf("0!: %d\n", ft_iterative_factorial(0));
	printf("-2!: %d\n", ft_iterative_factorial(-2));
	printf("11!: %d\n", ft_iterative_factorial(11));
	printf("12!: %d\n", ft_iterative_factorial(12));
	printf("13!: %d\n", ft_iterative_factorial(13));
	printf("14!: %d\n", ft_iterative_factorial(14));
	return (0);
}
