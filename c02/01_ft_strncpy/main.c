/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:00:28 by mateo             #+#    #+#             */
/*   Updated: 2023/11/29 10:34:00 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	s[10] = "123456789";
	char	d1[10] = "abc";
	char	d1_2[10] = "abc";
	char	d2[10] = "";
	char	d2_2[15] = "";
	char	d3[15] = "";
	char	d3_2[15] = "";
	char	d4[10] = "";
	char	d4_2[10] = "";
	char	d5[4] = "";
	char	d5_2[4] = "";
	
	printf("Before: s = %s, d1 = %s\n", s, d1);
	ft_strncpy(d1, s, 10);
	printf("After ft_strncpy: s = %s, d1 = %s\n", s, d1);
	strncpy(d1_2, s, 10);
	printf("After strncpy: 	  s = %s, d1 = %s\n", s, d1_2);
	printf("Before: s = %s, d2 = %s\n", s, d2);
	ft_strncpy(d2, s, 5);
	printf("After ft_strncpy: s = %s, d2 = %s\n", s, d2);
	strncpy(d2_2, s, 5);
	printf("After strncpy:    s = %s, d2 = %s\n", s, d2_2);
	printf("Before: s = %s, d3 = %s\n", s, d3);
	ft_strncpy(d3, s, 15);
	printf("After ft_strncpy: s = %s, d3 = %s\n", s, d3);
	strncpy(d3_2, s, 15);
	printf("After strncpy:    s = %s, d3 = %s\n", s, d3_2);
	printf("Before: s = %s, d4 = %s\n", s, d4);
	ft_strncpy(d4, s, 5);
	printf("After ft_strncpy: s = %s, d4 = %s\n", s, d4);
	strncpy(d4_2, s, 5);
	printf("After strncpy:    s = %s, d4 = %s\n", s, d4_2);
	printf("Before: s = %s, d5 = %s\n", s, d5);
	ft_strncpy(d5, s, 5);
	printf("After ft_strncpy: s = %s, d5 = %s\n", s, d5);
	strncpy(d5_2, s, 5);
	printf("After strncpy:     s = %s, d5 = %s\n", s, d5_2);
	return (0);
}
