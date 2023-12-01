/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:57:24 by mateo             #+#    #+#             */
/*   Updated: 2023/12/01 11:22:55 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	dest_l;
	unsigned int	src_l;
	unsigned int	total;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	total = src_l + dest_l;
	if (dest_l > size)
		total = src_l + size;
	i = 0;
	while ((src[i] != '\0') && ((dest_l + 1) < size))
	{
		dest[dest_l] = src[i];
		i++;
		dest_l++;
	}
	dest[dest_l] = '\0';
	return (total);
}
