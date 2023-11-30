/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric_v1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:56:37 by mateo             #+#    #+#             */
/*   Updated: 2023/11/27 23:56:37 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while ((str[i] != '\0') && (r == 1))
	{
		if (((str[i] >= '0') && (str[i] <= '9')))
			i++;
		else
			r = 0;
	}
	return (r);
}