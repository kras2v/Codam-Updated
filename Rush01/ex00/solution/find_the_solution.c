/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:16:30 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/25 23:00:38 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rush_01.h"

int	ft_is_num_allowed(int *grid[], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_grid(int *grid[])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	ft_arrcmp(int *arr1, int *arr2)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arr1[i] != arr2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_verify_the_solution(int *grid[], int *solved)
{
	if (ft_is_solved(grid) && !(*solved))
	{
		ft_print_grid(grid);
		(*solved) = 1;
	}
}

int	ft_find_the_solution(int *grid[], int row, int col, int *solved)
{
	int	num;

	num = 0;
	if (row == 4 && !(*solved))
	{
		ft_verify_the_solution(grid, solved);
		return (0);
	}
	if (col == 4 && !(*solved))
		return (ft_find_the_solution(grid, row + 1, 0, solved));
	while (num <= 4 && !(*solved))
	{
		if (ft_is_num_allowed(grid, row, col, num) && !(*solved))
		{
			grid[row][col] = num;
			if (ft_find_the_solution(grid, row, col + 1, solved))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
