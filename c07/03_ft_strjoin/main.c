/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <marsha.teo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:30:59 by mateo             #+#    #+#             */
/*   Updated: 2023/11/06 22:30:59 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char	*strs1[4] = {"abc def", "defd", "ghi00", "1 9 "};
	char	*s = ft_strjoin(4, strs1, ", ");
	printf("%s\n", s);
	char 	*t = ft_strjoin(0, strs1, ", ");
	printf("%s\n", t);

	char *strs2[1] = {"adf,"};
	char	*u = ft_strjoin(1, strs2, ", ");
	printf("%s\n", u);
	return (0);
}