/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:53:29 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/25 21:34:33 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rush_01.h"

void	ft_split_the_input(char *argv, int start_i, int *arr)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		if (start_i % 2 == 0)
		{
			arr[count] = argv[start_i] - '0';
			count++;
		}
		start_i++;
	}
}

int	ft_is_one_on_corners(int *arr_1, int *arr_2, int i_1, int i_2)
{
	if (arr_1[i_1] == 1)
	{
		if (arr_2[i_2] != 1)
			return (0);
	}
	else if (arr_2[i_2] == 1)
	{
		if (arr_1[i_1] != 1)
			return (0);
	}
	return (1);
}

int	ft_is_sum_within_limit(int *arr_1, int *arr_2)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arr_1[i] + arr_2[i] > 5)
			return (0);
		i++;
	}
	return (1);
}
