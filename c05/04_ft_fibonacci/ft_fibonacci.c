/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:36:52 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:36:52 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	r;

	r = 0;
	if (index < 0)
		return (-1);
	if (index == 1)
		return (1);
	if (index > 1)
		r = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (r);
}
