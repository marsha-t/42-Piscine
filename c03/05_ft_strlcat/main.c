/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:22:25 by mateo             #+#    #+#             */
/*   Updated: 2023/12/01 10:51:56 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	unsigned int 	n; 
	char	src[11] = "5678901";
	char	dest1[30]= "1234";	
	char	dest2[30]= "1234";
	char	dest3[20] = "1234";
	char	dest4[20] = "1234";
	char	dest5[20] = "1234";
	char	dest6[20] = "1234";
	char	dest7[20] = "1234";
	char	dest8[20] = "1234";
	
	n = ft_strlcat(dest1, src, 6); 
	printf("ft_strlcat: src: %s, dest: %s, return value: %d\n", src, dest1, n);
	n = strlcat(dest2, src, 6);
	printf("strlcat:    src: %s, dest: %s, return value: %d\n", src, dest2, n);
	n = ft_strlcat(dest3, src, 3); 
	printf("ft_strlcat: src: %s, dest: %s, return value: %d\n", src, dest3, n);	
	n = strlcat(dest4, src, 3); 
	printf("strlcat:    src: %s, dest: %s, return value: %d\n", src, dest4, n);
	n = ft_strlcat(dest5, src, 0); 
	printf("ft_strlcat: src: %s, dest: %s, return value: %d\n", src, dest5, n);	
	n = strlcat(dest6, src, 0); 
	printf("strlcat:    src: %s, dest: %s, return value: %d\n", src, dest6, n);
	n = ft_strlcat(dest7, src, 30); 
	printf("ft_strlcat: src: %s, dest: %s, return value: %d\n", src, dest7, n);	
	n = strlcat(dest8, src, 30); 
	printf("strlcat:    src: %s, dest: %s, return value: %d\n", src, dest8, n);
	return (0);
}
