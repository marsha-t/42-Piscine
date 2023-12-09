/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:10:56 by mateo             #+#    #+#             */
/*   Updated: 2023/12/09 15:13:11 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split(char *str, char *charset);

int	main(void)
{
	char str[] = "abc def ghi ";
	
	printf("\\\\\\ Example 1: space as separator\n");
	char charsep1[] = " ";
	char **ptr1;
	ptr1 = ft_split(str, charsep1);
	printf("%s\n", ptr1[0]);
	printf("%s\n", ptr1[1]);
	printf("%s\n", ptr1[2]);
	
	printf("\\\\\\ Example 2: space and tab as separator\n");
	char charsep2[] = " \t";
	char **ptr2;
	ptr2 = ft_split(str, charsep2);
	printf("%s\n", ptr2[0]);
	printf("%s\n", ptr2[1]);
	printf("%s\n", ptr2[2]);
	
	printf("\\\\\\ Example 3: tab as separator\n");
	char charsep3[] = "\t";
	char **ptr3;
	ptr3 = ft_split(str, charsep3);
	printf("%s\n", ptr3[0]);
	
	printf("\\\\\\ Example 4: space as separator but string only has space\n");
	char *str2 = " ";
	char **ptr4;
	ptr4 = ft_split(str2, charsep1);
	printf("%s\n", ptr4[0]);
	return (0);
}
