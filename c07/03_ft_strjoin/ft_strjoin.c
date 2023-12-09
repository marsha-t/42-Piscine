/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:31:04 by mateo             #+#    #+#             */
/*   Updated: 2023/11/06 22:31:04 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_totlen(char **strs, int size, char *sep)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			count++;
			j++;
		}
		i++;
	}
	i = 0;
	while (sep[i] != '\0')
		i++;
	return (count + (i * (size - 1)));
}

char	*ft_join(int size, char **strs, char *sep)
{
	int		i;
	int		p;
	int		j;
	char	*ptr;

	ptr = (char *)malloc((ft_totlen(strs, size, sep) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	p = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			ptr[p++] = strs[i][j++];
		if (i < (size - 1))
		{
			j = 0;
			while (sep[j] != '\0')
			ptr[p++] = sep[j++];
		}
		i++;
	}
	ptr[p] = '\0';
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;

	if (size == 0)
	{
		ptr = malloc(1);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = ft_join(size, strs, sep);
	return (ptr);
}
