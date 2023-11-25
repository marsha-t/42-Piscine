/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2_v1_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:50:53 by mateo             #+#    #+#             */
/*   Updated: 2023/11/24 09:50:53 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_it_all(char a1, char a2, char b1, char b2)
{
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
	if ((a1 != '9') || (a2 != '8'))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	char a1;
	char a2;
	char b1;
	char b2;

	a1 = 47;
	while (++a1 <= 57)
	{
		a2 = 47;
		while (++a2 <= 57)
		{
			b1 = 47; 
			while (++b1 <= 57)
			{
				b2 = 47; 
				while (++b2 <= 57)
				{
					if ((a1 != b1 || a2 != b2) && \
					((a1 < b1) || ((a1 == b1) && (a2 < b2))))
						ft_write_it_all(a1, a2, b1, b2);
				}
			}
		}
	}
}
