/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:39:05 by mateo             #+#    #+#             */
/*   Updated: 2023/11/23 22:39:05 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 9;
	printf("Before: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After:  a = %d, b = %d\n", a, b);
	return (0);
}
