/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:11:48 by mateo             #+#    #+#             */
/*   Updated: 2023/12/20 23:04:49 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char			s[4] = "abc";
	char			d1[4];
	char			d2[4];
	unsigned int	r;
	printf("Before: s = %s, d1 = %s, d2 = %s\n", s, d1, d2);
	r = ft_strlcpy(d1, s, 0);
	printf("After ft_strlcpy: return value: %u, s = %s, d1 = %s\n", r, s, d1);
	r = strlcpy(d2, s, 0);
	printf("After strlcpy:    return value: %u, s = %s, d2 = %s\n", r, s, d2);
	r = ft_strlcpy(d1, s, 3);
	printf("After ft_strlcpy: return value: %u, s = %s, d1 = %s\n", r, s, d1);
	r = strlcpy(d2, s, 3);
	printf("After strlcpy: 	  return value: %u, s = %s, d2 = %s\n", r, s, d2);
	return (0);
}
