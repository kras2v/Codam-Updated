/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:33:14 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/25 21:05:46 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rush_01.h"

void	ft_initialize_grid_with_zeros(int *grid[])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	**ft_allocate_grid(void)
{
	int	i;
	int	**grid;

	i = 0;
	grid = malloc(4 * sizeof(int *));
	while (i < 4)
	{
		grid[i] = malloc(4 * sizeof(int));
		i++;
	}
	ft_initialize_grid_with_zeros(grid);
	return (grid);
}
