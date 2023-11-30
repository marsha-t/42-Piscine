/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase_v2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:57:00 by mateo             #+#    #+#             */
/*   Updated: 2023/11/27 23:57:00 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_c_is_lowercase(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_c_is_lowercase(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
