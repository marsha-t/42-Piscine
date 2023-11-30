/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab_v2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:54:36 by mateo             #+#    #+#             */
/*   Updated: 2023/11/27 23:54:36 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int new_tab[size];
	int	i;
	i = 0;
	while (size - i - 1 >= 0)
	{
		new_tab[i] = tab[size - i - 1];
		i++;
	}
	i = 0;
	while (i <= size - 1)
	{
		tab[i] = new_tab[i];
		i++;
	}
}
