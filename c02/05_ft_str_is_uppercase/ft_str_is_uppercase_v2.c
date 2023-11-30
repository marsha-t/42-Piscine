/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase_v2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:57:15 by mateo             #+#    #+#             */
/*   Updated: 2023/11/27 23:57:15 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_c_is_uppercase(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_c_is_uppercase(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
