/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:04 by mateo             #+#    #+#             */
/*   Updated: 2023/11/13 10:59:04 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*range;
	int	d;
	int	i;

	d = ft_ultimate_range(&range, 3, 7);
	printf("ft_ultimate_range(range, 3, 7): ");
	printf("size: %d\n", d);
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", range[i]);
	}
	d = ft_ultimate_range(&range, -4, 0);
	printf("\nft_ultimate_range(range, -4, 0): ");
	printf("size: %d\n", d);
	for (i = 0; i < 4; ++i)
	{
		printf("%d, ", range[i]);
	}
	d = ft_ultimate_range(&range, 0, 0);
	printf("\nft_ultimate_range(range, 0, 0): ");
	printf("size: %d\n", d);
	if (range == 0)
		printf("Null pointer returned\n");
	
	d = ft_ultimate_range(&range, 7, 3);
	printf("ft_ultimate_range(range, 7, 3): ");
	printf("size: %d\n", d);
	if (range == 0)
		printf("Null pointer returned\n");
	return (0);
}
