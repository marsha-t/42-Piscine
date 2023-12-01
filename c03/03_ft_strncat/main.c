/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:30 by mateo             #+#    #+#             */
/*   Updated: 2023/11/30 23:56:17 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
	char    str1[15] = "abcd";
	char    str2[15] = "abcd";
	char    str3[6] = "12345";
	ft_strncat(str1, str3, 9);
	printf("ft_strncat: str1: %s, str3: %s\n" , str1, str3);
	strncat(str2, str3, 9);
	printf("strncat:    str2: %s, str3: %s\n" , str2, str3);
	char    str4[5] = "abcd";
	char    str5[5] = "abcd";
	char    str6[6] = "12345";
	ft_strncat(str4, str6, 3);
	printf("ft_strncat: str4: %s, str6: %s\n" , str4, str6);
	strncat(str5, str6, 3);
	printf("strncat:    str5: %s, str6: %s\n" , str5, str6);
	return (0);
}