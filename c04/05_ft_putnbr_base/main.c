/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:05:23 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:05:23 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	int	a;

	a = -2147483648;
	ft_putnbr_base(a, "01");
	write(1, "\n", 1);
	a = -42;
	ft_putnbr_base(a, "01");
	write(1, "\n", 1);
	a = 13;
	ft_putnbr_base(a, "34");
	write(1, "\n", 1);
	a = 30;
	ft_putnbr_base(a, "abc");
	write(1, "\n", 1);
	return (0);
}
