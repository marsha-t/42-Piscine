/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:19:29 by mateo             #+#    #+#             */
/*   Updated: 2023/11/30 21:12:49 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int main(void)
{
    char    str1[] = "abcde";
    char    str2[] = "ab";
    char    str3[] = "Abcd";
    char    str4[] = "0d";
    char    str5[] = "\ns";
    char    str6[] = " s";
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str2));
    printf("strcmp:    %d\n", strcmp(str1, str2));
    printf("ft_strcmp: %d\n", ft_strcmp(str3, str1));
    printf("strcmp:    %d\n", strcmp(str3, str1));
    printf("ft_strcmp: %d\n", ft_strcmp(str2, str3));
    printf("strcmp:    %d\n", strcmp(str2, str3));
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str1));
    printf("strcmp:    %d\n", strcmp(str1, str1));
    printf("ft_strcmp: %d\n", ft_strcmp(str1, str4));
    printf("strcmp:    %d\n", strcmp(str1, str4));
    printf("ft_strcmp: %d\n", ft_strcmp(str2, str5));
    printf("strcmp:    %d\n", strcmp(str2, str5));
    printf("ft_strcmp: %d\n", ft_strcmp(str5, str4));
    printf("strcmp:    %d\n", strcmp(str5, str4));
    printf("ft_strcmp: %d\n", ft_strcmp(str5, str6));
    printf("strcmp:    %d\n", strcmp(str5, str6));
    return (0);
}