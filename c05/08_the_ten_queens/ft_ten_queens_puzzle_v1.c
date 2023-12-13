/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateo <mateo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:11:03 by mateo             #+#    #+#             */
/*   Updated: 2023/12/09 23:11:03 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int ft_samerow(int *arr, int i)
{
	int j; 

	if (i == 0)
		return (1);
	j = 0; 
	while (j < i)
	{
		if (arr[i] == arr[j])
			return (0);
		j++;
	}
	return (1);
}

int ft_diag(int *arr, int i)
{
	int j; 
	
	if (i == 0)
		return (1);
	j = 0;
	while (j < i)
	{
		if (arr[j] == arr[i] + j - i)
			return (0);
		if (arr[i] == arr[j] + j - i)
			return (0);
		j++;
	}
	return (1);
}

void ft_print_array(int *arr)
{
	int j; 
	char c; 

	j = 0;
	while (j < 10)
	{
		c = arr[j] + '0';
		write(1, &c, 1);
		j++;
	}
	write(1, "\n", 1);
}

void ft_check_print(int *arr, int i, int *count)
{
	while (arr[0] <= 9)
	{
		if (ft_samerow(arr, i) && ft_diag(arr, i) && (arr[i] <= 9))
		{
			if (i < 9)
				i++;
			else 
			{
				ft_print_array(arr);
				(*count)++;
				arr[i--] = 0;
				arr[i]++;
			}
		}
		else 
		{
			if (arr[i] < 9)
				arr[i]++;
			else
			{
				arr[i--] = 0;
				arr[i]++;
			}
		}
	}
}

int ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int count;

	i = 0;
	while (i < 10)
		arr[i++] = 0;
	
	count = 0;
	i = 0;
	ft_check_print(arr, i, &count);
	return (count);
}
