/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:17:30 by mateo             #+#    #+#             */
/*   Updated: 2023/11/07 09:17:30 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	printf("%s\n", ft_convert_base(" --+101010", "01", "0123456789"));
	printf("%s\n", ft_convert_base(" --+101010", "01", "ab"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "01"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "ab"));
	printf("%s\n", ft_convert_base("+2147483647", "0123456789", "012345"));
	return (0);	
}
