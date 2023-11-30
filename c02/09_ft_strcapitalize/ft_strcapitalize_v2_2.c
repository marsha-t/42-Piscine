/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_v2_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:18:04 by mateo             #+#    #+#             */
/*   Updated: 2023/11/28 17:18:04 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_c_is_alphaumeric(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	else if ((c >= 'a') && (c <= 'z'))
		return (1);
	else if (((c >= '0') && (c <= '9')))
		return (1);
	return (0);
}

int	ft_c_is_lowercase(char c)
{
	if (((c >= 'a') && (c <= 'z')))
		return (1);
	return (0);
}

int	ft_c_is_uppercase(char c)
{
	if (((c >= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str = ft_strupcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_c_is_lowercase(str[i])) || (ft_c_is_uppercase(str[i])))
		{
			if ((ft_c_is_uppercase(str[i])) && (ft_c_is_alphaumeric(str[i - 1])))
				str[i] = str[i] + ('a' - 'A');
		}
		i++;
	}
	return (str);
}
