/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable_v2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:19:52 by mateo             #+#    #+#             */
/*   Updated: 2023/11/28 10:19:52 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_c_is_printable(char c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_c_is_printable(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
