/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:52:51 by mateo             #+#    #+#             */
/*   Updated: 2023/12/28 09:52:51 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_last(t_list *begin_list);

int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	*empty;
	t_list	*last;

	node0 = ft_create_elem("abc");
	node1 = ft_create_elem("def");
	node2 = ft_create_elem("ghi");
	node0->next = node1;
	node1->next = node2;
	printf("List: %s, %s, %s\n", (node0)->data, (node0)->next->data, (node0)->next->next->data);
	last = ft_list_last(node0);
	printf("Last node: %s\n", last->data);
	printf("Empty List:\n");
	empty = 0;
	if (ft_list_last(empty) == 0)
		printf("null");
	return (0);
}
