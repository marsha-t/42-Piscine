/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:45:17 by mateo             #+#    #+#             */
/*   Updated: 2023/12/01 18:45:17 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);

int main(void)
{
	write(1, "n = 1\n", 6);
	ft_print_combn(1);
	write(1, "\nn = 2\n", 7);
	ft_print_combn(2);
	write(1, "\nn = 3\n", 7);
	ft_print_combn(3);
	write(1, "\nn = 4\n", 7);
	ft_print_combn(4);
	write(1, "\nn = 5\n", 7);
	ft_print_combn(5);
	write(1, "\nn = 6\n", 7);
	ft_print_combn(6);
	write(1, "\nn = 7\n", 7);
	ft_print_combn(7);
	write(1, "\nn = 8\n", 7);
	ft_print_combn(8);
	write(1, "\nn = 9\n", 7);
	ft_print_combn(9);
	return (0);
}