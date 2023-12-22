/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:53:35 by mateo             #+#    #+#             */
/*   Updated: 2023/11/13 23:53:35 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_map(int *tab, int length, int (*f)(int));

int	ft_sq(int n)
{
	return (n * n);
}

int	main(void)
{
	int	i;
	int	*ptr;
	int	length;
	int	*ptr2;

	length = 5;
	ptr = (int *)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		ptr[i] = i;
		i++;
	}
	ptr2 = ft_map(ptr, length, &ft_sq);
	i = 0;
	while (i < length)
	{
		printf("%d\n", ptr2[i]);
		i++;
	}
}
