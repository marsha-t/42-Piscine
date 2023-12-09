/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:54:11 by mateo             #+#    #+#             */
/*   Updated: 2023/11/13 10:54:11 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	i;
	int	*ptr;

	printf("ft_range(3,7): ");
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", ft_range(3, 7)[i]);
	}
	printf("\nft_range(-4, 0): ");
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", ft_range(-4, 0)[i]);
	}
	printf("\nft_range(0, 0): ");
	ptr = ft_range(0, 0);
	if (ptr == 0)
		printf("Null pointer returned\n");
	printf("ft_range(7,3): ");
	ptr = ft_range(7, 3);
	if (ptr == 0)
		printf("Null pointer returned\n");
	return (0);
}
