/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:10:41 by mateo             #+#    #+#             */
/*   Updated: 2023/11/28 11:31:27 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	str2[] = "abC+aSa+AsA de0a AbC";
	char	str3[] = "123";
	char	str4[1] = "";
	char	str5[1];
	
	ft_strcapitalize(str1);
	ft_strcapitalize(str2);
	ft_strcapitalize(str3);
	ft_strcapitalize(str4);
	ft_strcapitalize(str5);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	printf("%s\n", str5);
	return (0);
}
