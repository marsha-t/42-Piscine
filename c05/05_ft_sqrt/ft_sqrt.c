/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:37:18 by mateo             #+#    #+#             */
/*   Updated: 2023/11/05 20:37:18 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	test_sq;

	test_sq = 1;
	while ((test_sq <= 46340) && (test_sq * test_sq <= nb))
	{
		if (test_sq * test_sq == nb)
			return (test_sq);
		test_sq++;
	}
	return (0);
}