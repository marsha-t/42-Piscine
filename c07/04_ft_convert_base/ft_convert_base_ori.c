/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:16:21 by mateo             #+#    #+#             */
/*   Updated: 2023/11/07 09:16:21 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_base_ok(char *base)
{
	int	i;
	int	j;
	int	base_l;

	base_l = 0;
	while (base[base_l] != '\0')
		base_l++;
	if ((base_l == 0) || (base_l == 1))
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == '+') || (base[i] == '-') \
		|| (base[i] < 32) || (base[i] > 126))
			return (0);
		j = i + 1;
		while (j < (base_l - 1))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	r;
	int	s;
	int	base_l;

	base_l = 0;
	while (base[base_l] != '\0')
		base_l++;
	s = 1;
	r = 0;
	i = 0;
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (is_base(str[i], base) > -1)
		r = (r * base_l) + (is_base(str[i++], base));
	return (r * s);
}

char	*ft_itoa_base(long long x, char *base_to, int count)
{
	int		i;
	int		base_l;
	char	*ptr;

	base_l = 0;
	while (base_to[base_l] != '\0')
		base_l++;
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (0);
	ptr[count] = '\0';
	i = 0;
	if (x < 0)
	{
		ptr[0] = '-';
		x = -x;
	}
	while (x > 0)
	{
		ptr[count - 1] = base_to[(x % base_l)];
		x = x / base_l;
		count--;
	}
	return (ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ptr;
	int		count;
	int		base_l;
	long long	x;

	if ((ft_base_ok(base_from) == 0) || (ft_base_ok(base_to) == 0))
		return (0);
	x = ft_atoi_base(nbr, base_from);
	base_l = 0;
	while (base_to[base_l] != '\0')
		base_l++;
	count = 1;
	if (x < -1)
	{
		count++;
		x = -x;
	}
	while (x >= base_l)
	{
		x = x / base_l;
		count++;
	}
	x = ft_atoi_base(nbr, base_from);
	ptr = ft_itoa_base(x, base_to, count);
	return (ptr);
}
