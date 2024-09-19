/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_validation.c.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:34:10 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/25 21:40:04 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rush_01.h"

static int	**g_col_row;

int	ft_is_solved(int *grid[])
{
	int	**col_row;
	int	is_solved;

	col_row = ft_allocate_grid();
	ft_calc_up(grid, col_row[0]);
	ft_calc_down(grid, col_row[1]);
	ft_calc_left(grid, col_row[2]);
	ft_calc_right(grid, col_row[3]);
	is_solved = (ft_arrcmp(col_row[0], g_col_row[0])
			&& ft_arrcmp(col_row[1], g_col_row[1])
			&& ft_arrcmp(col_row[2], g_col_row[2])
			&& ft_arrcmp(col_row[3], g_col_row[3]));
	ft_free_grid(col_row);
	if (is_solved)
	{
		ft_free_grid(g_col_row);
	}
	return (is_solved);
}

int	ft_are_values_valid(char *argv)
{
	g_col_row = ft_allocate_grid();
	ft_split_the_input(argv, 0, g_col_row[0]);
	ft_split_the_input(argv, 8, g_col_row[1]);
	ft_split_the_input(argv, 16, g_col_row[2]);
	ft_split_the_input(argv, 24, g_col_row[3]);
	if (ft_is_sum_within_limit(g_col_row[0], g_col_row[1])
		&& ft_is_sum_within_limit(g_col_row[2], g_col_row[3])
		&& ft_is_one_on_corners(g_col_row[0], g_col_row[3], 3, 0)
		&& ft_is_one_on_corners(g_col_row[3], g_col_row[1], 3, 3)
		&& ft_is_one_on_corners(g_col_row[1], g_col_row[2], 0, 3)
		&& ft_is_one_on_corners(g_col_row[2], g_col_row[0], 0, 0))
	{
		return (1);
	}
	return (0);
}
