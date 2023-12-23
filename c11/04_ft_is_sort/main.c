/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:56:01 by mateo             #+#    #+#             */
/*   Updated: 2023/11/13 23:56:01 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_cmp(int x, int y)
{
	if (x < y)
		return (-1);
	else if (x == y)
		return (0);
	return (1);
}

int	main(void)
{
	int	ptr[] = {9,8,7,6,5,4,3,2,1,0};
	int	ptr2[] = {0,1,2,3,4,5,6,7,9,8};
	int	ptr3[] = {0,1,2,3,4,5,6,7,8,9};

	printf("%d\n", ft_is_sort(ptr, 10, &ft_cmp));
	printf("%d\n", ft_is_sort(ptr2, 10, &ft_cmp));
	printf("%d\n", ft_is_sort(ptr3, 10, &ft_cmp));
	return (0);
}
