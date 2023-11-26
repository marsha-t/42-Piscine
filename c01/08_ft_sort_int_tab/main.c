/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:41:08 by mateo             #+#    #+#             */
/*   Updated: 2023/11/23 22:41:08 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	num[4];

	num[0] = 2;
	num[1] = 1;
	num[2] = 3;
	num[3] = 0;
	printf("Before: %d, %d, %d, %d\n", num[0], num[1], num[2], num[3]);
	ft_sort_int_tab(num, 4);
	printf("After:  %d, %d, %d, %d\n", num[0], num[1], num[2], num[3]);
	return (0);
}
