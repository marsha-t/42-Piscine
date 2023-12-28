/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:19:04 by mateo             #+#    #+#             */
/*   Updated: 2023/11/18 00:19:04 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
	int	size;
	t_list *current;

	size = 0;
	current = begin_list;
	while(current)
	{
		current = current-> next;
		size++;
	}
	return (size);
}