/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:56:20 by mateo             #+#    #+#             */
/*   Updated: 2023/11/25 10:56:20 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ft_print_combn(int n)
{
	char	arr[n];
	int		i;
	char	d;

	i = 0;
	d = '0';
	while (i < n)
	{
		while (d <= '9')
		{
			arr[i] = 
			d++;
		}
		i++;
	}
}