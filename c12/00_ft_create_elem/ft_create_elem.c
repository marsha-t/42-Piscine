/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:21:01 by mateo             #+#    #+#             */
/*   Updated: 2023/12/25 11:01:25 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list *new;
	
	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->data = data;
		new->next = 0;	
	}
	return (new);
}
