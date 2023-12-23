/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:55:09 by mateo             #+#    #+#             */
/*   Updated: 2023/11/13 23:55:09 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*));

int	ft_a(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a')
			return (1);
		i++;
	}
	return (0);
}

int	main (void)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * 4);
	for (int i = 0; i < 3; i++)
	{
		ptr[i] = (char *)malloc(2);
	}
	ptr[3] = 0;
	ptr[0] = "a";
	ptr[1] = "b";
	ptr[2] = "c";
	printf("%d\n", ft_count_if(ptr, 3, &ft_a));
	ptr[0] = "a";
	ptr[1] = "a";
	ptr[2] = "a";
	printf("%d\n", ft_count_if(ptr, 3, &ft_a));
	ptr[0] = "b";
	ptr[1] = "b";
	ptr[2] = "b";
	printf("%d\n", ft_count_if(ptr, 3, &ft_a));
}
