/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:37:26 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:37:26 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);

int	main(void)
{
	int	i;
	int	sq;

	for (i = 1; i < 9; i++)
	{
		sq = i * i;
		printf("sq of %d: %d --> sqrt: %d\n", i, sq, ft_sqrt(sq));
	}
	printf("sqrt of 14: %d\n", ft_sqrt(14));
	printf("sqrt of -2: %d\n", ft_sqrt(-2));
	printf("sqrt of 2147395600: %d\n", ft_sqrt(2147395600));
	printf("sqrt of 2147483647: %d\n", ft_sqrt(2147483647));
	return (0);
}
