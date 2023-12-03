/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:00:52 by mateo             #+#    #+#             */
/*   Updated: 2023/12/03 13:00:52 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	char	str1[20] = "-101010";
    char    str2[] = "1101";
    char    str3[] = "39";
    char    str4[] = "1010";
    char    str5[] = "baba";
    char    str6[] = "4434";
	printf("str1: %d\n", ft_atoi_base(str1, "01"));
    printf("str2: %d\n", ft_atoi_base(str2, "01"));
    printf("str3: %d\n", ft_atoi_base(str3, "0123456789abcdef"));
    printf("str4: %d\n", ft_atoi_base(str4, "012"));
    printf("str5: %d\n", ft_atoi_base(str5, "abc"));
    printf("str6: %d\n", ft_atoi_base(str6, "34"));
	return (0);
}

