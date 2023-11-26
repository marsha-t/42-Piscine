/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:39:37 by mateo             #+#    #+#             */
/*   Updated: 2023/11/23 22:39:37 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 3;
	printf("Before: a = %d, b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("After:  a = %d, b = %d\n", a, b);
	return (0);
}
