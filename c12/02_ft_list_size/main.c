/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:59:11 by mateo             #+#    #+#             */
/*   Updated: 2023/12/27 09:59:11 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list);

int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	*empty;

	node0 = ft_create_elem("abc");
	node1 = ft_create_elem("def");
	node2 = ft_create_elem("ghi");
	node0->next = node1;
	node1->next = node2;
	printf("List: %s, %s, %s\n", (node0)->data, (node0)->next->data, (node0)->next->next->data);
	printf("Size: %d\n", ft_list_size(node0));
	empty = 0;
	printf("Empty List:\n");
	printf("Size: %d\n", ft_list_size(empty));
	return (0);
}
