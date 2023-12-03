/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn_v1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:24:06 by mateo             #+#    #+#             */
/*   Updated: 2023/12/02 10:24:06 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_array(int *array, int n)
{
	int		i;
	char	c;

	i = -1;
	while (++i < n)
	{
		c = array[i] + '0';
		write(1, &c, 1);
	}
	if (array[0] != (10 - n))
		write(1, ", ", 2);
}

void	ft_increment_and_reset(int *array, int n)
{
	int max[n];
	int i;
	
	i = -1;
	while (++i < n)
		max[i] = 10 - n + i;
	i = n - 1;
	while (array[i] == max[i])
		i--;
	if (i == -1)
	{
		array[0] = 10;
		return ;
	}
	array[i]++;
	while (++i < n)
		array[i] = array[i - 1] + 1;
}

void	ft_print_combn(int n)
{
	int	array[9];
	int	i;

	if ((n < 1) || (n > 9))
		return ;
	i = -1;
	while (++i < n)
		array[i] = i;
	while (array[0] <= (10 - n))
	{
		ft_print_array(array, n);
		if (array[n - 1] < 9)
			array[n - 1]++;
		else
			ft_increment_and_reset(array, n);
	}
}
