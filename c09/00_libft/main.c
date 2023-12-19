/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:23:45 by mateo             #+#    #+#             */
/*   Updated: 2023/12/19 20:23:45 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int	main(void)
{
	ft_putchar('a');
	ft_putstr("\nabc\n");
	int	i;
	i = ft_strlen("123") + '0';
	write(1, &i, 1);
	write(1, "\n", 1);
	i = ft_strcmp("c", "a") + '0';
	write(1, &i, 1);
	write(1, "\n", 1);
	i = 48;
	int j = 49;
	ft_swap(&i, &j);
	write(1, &i, 1);
	write(1, "\n", 1);
	write(1, &j, 1);
	return (0);
}