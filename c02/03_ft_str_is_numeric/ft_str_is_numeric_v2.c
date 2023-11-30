/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric_v2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:56:43 by mateo             #+#    #+#             */
/*   Updated: 2023/11/27 23:56:43 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_c_is_numeric(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_c_is_numeric(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
