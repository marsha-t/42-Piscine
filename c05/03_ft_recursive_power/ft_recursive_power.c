/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:36:23 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:36:23 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	r;

	if (power < 0)
		return (0);
	r = 1;
	if (power > 0)
		r = nb * ft_recursive_power(nb, power - 1);
	return (r);
}
