/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:54:58 by mateo             #+#    #+#             */
/*   Updated: 2023/11/29 10:22:53 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	s[4] = "abc";
	char	d1[4] = "def";
	char	d2[4] = "def";
	char	d3[4];
	char	d4[4];

	printf("Before: s = %s, d1 = %s, d2 = %s\n", s, d1, d2);
	ft_strcpy(d1, s);
	printf("After ft_strcpy: s = %s, d1 = %s\n", s, d1);
	strcpy(d2, s);
	printf("After strcpy:    s = %s, d2 = %s\n", s, d2);
	printf("Before: s = %s, d3 = %s, d4 = %s\n", s, d3, d4);
	ft_strcpy(d3, s);
	printf("After ft_strcpy: s = %s, d3 = %s\n", s, d3);
	strcpy(d4, s);
	printf("After strcpy:    s = %s, d4 = %s\n", s, d4);
	return (0);
}