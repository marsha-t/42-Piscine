/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:02:45 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:02:45 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	char	str1[20] = "   ---+--+1234a567";
	char	str2[20] = " -+--345678a";
	char	str3[20] = "\n12345678";
	char	str4[20] = "a12345678";
	char	str5[20] = "--12345678";
	char	str6[20] = "9999999999";

	printf("str1: %d\n", ft_atoi(str1));
	printf("str2: %d\n", ft_atoi(str2));
	printf("str3: %d\n", ft_atoi(str3));
	printf("str4: %d\n", ft_atoi(str4));
	printf("str5: %d\n", ft_atoi(str5));
	printf("str6: %d\n", ft_atoi(str6));
	return (0);
}
