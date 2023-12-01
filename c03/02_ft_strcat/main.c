/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:09 by mateo             #+#    #+#             */
/*   Updated: 2023/11/30 22:53:54 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char    *ft_strcat(char *dest, char *src);

int main(void)
{
	char    str1[10] = "abcd";
	char    str2[10] = "abcd";
	char    str3[3] = "fg";
	ft_strcat(str1, str3);
	printf("ft_strcat: str1: %s, str3: %s\n", str1, str3);
	strcat(str2, str3);
	printf("strcat:    str2: %s, str3: %s\n", str2, str3);
	char    str4[5] = "abcd";
	char    str5[5] = "abcd";
	char    str6[3] = "fg";
	ft_strcat(str4, str6);
	printf("ft_strcat: str4: %s, str6: %s\n", str4, str6);
	strcat(str5, str6);
	printf("strcat:    str5: %s, str6: %s\n", str5, str6);
	return (0);
}