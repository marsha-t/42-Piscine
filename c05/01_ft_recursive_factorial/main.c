/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:35:47 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:35:47 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb);

int	main(void)
{
	printf("3!: %d\n", ft_recursive_factorial(3));
	printf("2!: %d\n", ft_recursive_factorial(2));
	printf("1!: %d\n", ft_recursive_factorial(1));
	printf("0!: %d\n", ft_recursive_factorial(0));
	printf("-2!: %d\n", ft_recursive_factorial(-2));
	printf("11!: %d\n", ft_recursive_factorial(11));
	printf("12!: %d\n", ft_recursive_factorial(12));
	printf("13!: %d\n", ft_recursive_factorial(13));
	printf("14!: %d\n", ft_recursive_factorial(14));
	return (0);
}
