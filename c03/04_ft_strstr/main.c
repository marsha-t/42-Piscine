/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:21:51 by mateo             #+#    #+#             */
/*   Updated: 2023/12/01 00:20:35 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	haystack[20] = "Point132  fd01";
	char	needle1[2] = "m";
	char	needle2[3] = "oi";
	char	needle3[2] = "1";
	char	needle4[2] = "0";

	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle1), strstr(haystack, needle1));
	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle2), strstr(haystack, needle2));
	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle3), strstr(haystack, needle3));
	printf("result: ft_strstr: %s\n           strstr: %s\n", ft_strstr(haystack, needle4), strstr(haystack, needle4));
	return (0);
}
