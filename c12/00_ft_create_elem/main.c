/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:44:41 by mateo             #+#    #+#             */
/*   Updated: 2023/12/25 10:44:41 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data);

int	main(void)
{
	char str[] = "abc";
	t_list *new;

	new = ft_create_elem(str);
	printf("%s", new->data);
	return (0);
}
