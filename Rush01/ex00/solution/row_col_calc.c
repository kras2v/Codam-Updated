/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 13:41:09 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/25 21:05:57 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rush_01.h"

void	ft_calc_up(int *grid[], int *p_arr)
{
	int	i;
	int	j;
	int	count;
	int	highest_nbr;

	j = 0;
	while (j < 4)
	{
		count = 1;
		highest_nbr = grid[0][j];
		i = 1;
		while (i <= 3)
		{
			if (grid[i][j] > highest_nbr)
			{
				highest_nbr = grid[i][j];
				count++;
			}
			i++;
		}
		p_arr[j] = count;
		j++;
	}
}

void	ft_calc_down(int *grid[], int *p_arr)
{
	int	i;
	int	j;
	int	count;
	int	highest_nbr;

	j = 0;
	while (j < 4)
	{
		count = 1;
		highest_nbr = grid[3][j];
		i = 2;
		while (i >= 0)
		{
			if (grid[i][j] > highest_nbr)
			{
				highest_nbr = grid[i][j];
				count++;
			}
			i--;
			p_arr[j] = count;
		}
		j++;
	}
}

void	ft_calc_left(int *grid[], int *p_arr)
{
	int	i;
	int	j;
	int	count;
	int	highest_nbr;

	i = 0;
	while (i < 4)
	{
		count = 1;
		highest_nbr = grid[i][0];
		j = 1;
		while (j <= 3)
		{
			if (grid[i][j] > highest_nbr)
			{
				highest_nbr = grid[i][j];
				count = count + 1;
			}
			j++;
		}
		p_arr[i] = count;
		i++;
	}
}

void	ft_calc_right(int *grid[], int *p_arr)
{
	int	i;
	int	j;
	int	count;
	int	highest_nbr;

	i = 0;
	while (i < 4)
	{
		count = 1;
		highest_nbr = grid[i][3];
		j = 2;
		while (j >= 0)
		{
			if (grid[i][j] > highest_nbr)
			{
				highest_nbr = grid[i][j];
				count = count + 1;
			}
			j--;
		}
		p_arr[i] = count;
		i++;
	}
}
