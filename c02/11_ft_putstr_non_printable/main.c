/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:12:56 by mateo             #+#    #+#             */
/*   Updated: 2023/11/30 10:09:02 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str[] = "Coucou\ntu \tvas \vbien ?";
	char	str2[] = "a \a b\b f\f r\r";
	char	str3[2]; 
	str3[0] = 127;
	str3[1] = '\0';
	printf("Original: %s\nAfter: ", str);
	ft_putstr_non_printable(str);
	printf("\nOriginal: %s\nAfter: ", str2);
	ft_putstr_non_printable(str2);
	printf("\nOriginal: %s\nAfter: ", str3);
	ft_putstr_non_printable(str3);
	return (0);
}
