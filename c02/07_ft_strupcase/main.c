/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:08:38 by mateo             #+#    #+#             */
/*   Updated: 2023/11/28 10:51:11 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	str1[4] = "abc";
	char	str2[4] = "AbC";
	char	str3[6] = "d 0 e";
	char	str4[1] = "";
	char	str5[1];

	ft_strupcase(str1);
	ft_strupcase(str2);
	ft_strupcase(str3);
	ft_strupcase(str4);
	ft_strupcase(str5);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	printf("%s\n", str5);
	return (0);
}
