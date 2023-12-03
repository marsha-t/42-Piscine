/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:11:47 by mateo             #+#    #+#             */
/*   Updated: 2023/12/01 23:27:42 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_c_is_numeric(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	ft_c_is_whitespace(char c)
{
	if ((c == ' ' || c == '\n' || c == '\t' || \
	c == '\v' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	r;
	int	i;
	int	s;

	r = 0;
	i = 0;
	s = 1;
	while (ft_c_is_whitespace(str[i]))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (ft_c_is_numeric(str[i]))
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r * s);
}
