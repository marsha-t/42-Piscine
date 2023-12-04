/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:35:52 by mateo             #+#    #+#             */
/*   Updated: 2023/12/04 15:42:06 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_c_printable(char c)
{
	if (((c >= 32) && (c <= 126)))
		return (1);
	return (0);
}

int	ft_base_ok(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == '+') || (base[i] == '-') \
		|| ft_c_printable(base[i]) == 0)
			return (0);
		j = i + 1;
		while (j < ft_strlen(base) - 1)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	x;
	int		b;

	x = nbr;
	b = ft_strlen(base);
	if (ft_base_ok(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			x = -x;
		}
		if (x >= b)
			ft_putnbr_base(x / b, base);
		write(1, &base[x % b], 1);
	}
}
