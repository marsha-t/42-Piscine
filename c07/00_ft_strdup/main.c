/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:59 by mateo             #+#    #+#             */
/*   Updated: 2023/11/13 10:52:59 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	str1[20] = "abcd";

	printf("String value: %s\n", str1);
	printf("ft_strdup string value: %s\n", ft_strdup(str1));
	printf("strdup string value: %s\n", strdup(str1));
	printf("String location: %p\n", str1);
	printf("ft_strdup string location: %p\n", ft_strdup(str1));
	printf("strdup string location: %p\n", strdup(str1));
	char str2[] = "";
	printf("String value: %s\n", str2);
	printf("ft_strdup string value: %s\n", ft_strdup(str2));
	printf("strdup string value: %s\n", strdup(str2));
	printf("String location: %p\n", str2);
	printf("ft_strdup string location: %p\n", ft_strdup(str2));
	printf("strdup string location: %p\n", strdup(str2));
	return (0);
}
