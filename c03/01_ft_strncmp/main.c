/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:20:02 by mateo             #+#    #+#             */
/*   Updated: 2023/11/30 23:51:15 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
    char    str1[] = "abcde";
    char    str2[] = "ab";
    char    str3[] = "Abcd";
    char    str4[] = "0d";
    char    str5[] = "\n";
    char    str6[] = " s";
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str1, 4));
    printf("strncmp:    %d\n", strncmp(str1, str1, 4));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 2));
    printf("strncmp:    %d\n", strncmp(str1, str2, 2));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str2, 3));
    printf("strncmp:    %d\n", strncmp(str1, str2, 3));
    printf("ft_strncmp: %d\n", ft_strncmp(str3, str1, 6));
    printf("strncmp:    %d\n", strncmp(str3, str1, 6));
    printf("ft_strncmp: %d\n", ft_strncmp(str2, str3, 0));
    printf("strncmp:    %d\n", strncmp(str2, str3, 0));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str1, 10));
    printf("strncmp:    %d\n", strncmp(str1, str1, 10));
    printf("ft_strncmp: %d\n", ft_strncmp(str1, str4, 1));
    printf("strncmp:    %d\n", strncmp(str1, str4, 1));
    printf("ft_strncmp: %d\n", ft_strncmp(str2, str5, 2));
    printf("strncmp:    %d\n", strncmp(str2, str5, 2));
    printf("ft_strncmp: %d\n", ft_strncmp(str5, str4, 3));
    printf("strncmp:    %d\n", strncmp(str5, str4, 3));
    printf("ft_strncmp: %d\n", ft_strncmp(str5, str6, 1));
    printf("strncmp:    %d\n", strncmp(str5, str6, 1));
    return (0);
}