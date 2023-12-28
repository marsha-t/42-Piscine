/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:22:21 by mateo             #+#    #+#             */
/*   Updated: 2023/12/27 09:22:21 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);

int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	**begin;

	node0 = ft_create_elem("abc");
	node1 = ft_create_elem("def");
	node2 = ft_create_elem("ghi");
	node0->next = node1;
	node1->next = node2;
	begin = &node0;
	printf("Before: %s, %s, %s\n", (*begin)->data, (*begin)->next->data, (*begin)->next->next->data);
	ft_list_push_front(begin, "123");
	printf("After:  %s, %s, %s, %s\n", (*begin)->data, (*begin)->next->data, (*begin)->next->next->data, (*begin)->next->next->next->data);
	return (0);
}
