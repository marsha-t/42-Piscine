/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:09:43 by mateo             #+#    #+#             */
/*   Updated: 2023/11/28 11:11:50 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	str1[4] = "ABC";
	char	str2[4] = "aBc";
	char	str3[6] = "D 0 E";
	char	str4[1] = "";
	char	str5[1];

	ft_strlowcase(str1);
	ft_strlowcase(str2);
	ft_strlowcase(str3);
	ft_strlowcase(str4);
	ft_strlowcase(str5);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	printf("%s\n", str5);
	return (0);
}
