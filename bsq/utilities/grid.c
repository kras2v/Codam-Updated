/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:36:13 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/03 22:12:51 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

char	**ft_allocate_grid(int width, int height)
{
	int		i;
	char	**grid;

	i = 0;
	grid = (char **)malloc(height * sizeof(char *));
	if(!grid)
		ft_raise_error_and_quit("Error allocating memory\n");
	while (i < height)
	{
		grid[i] = (char *)malloc(width * sizeof(char));
		if(!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			ft_raise_error_and_quit("Error allocating memory\n");
		}
		i++;
	}
	return (grid);
}

void	ft_fill_the_grid(char *buffer, int k, t_map_info *map_info)
{
	int		i;
	int		j;

	i = 0;
	map_info->grid = ft_allocate_grid(map_info->width, map_info->height);
	while(i < map_info->height)
	{
		j = 0;
		while(j < map_info->width)
		{
			if (buffer[k] == '\0') {
				ft_raise_error_and_quit("Buffer ended unexpectedly\n");
			}
			if(buffer[k] != '\n')
			{
				map_info->grid[i][j] = buffer[k];
				k++;
			}
			else 
				k++;
			j++;
		}
		i++;
	}
}

void	ft_print_map_grid(t_map_info map_info)
{
	int	i;
	int	j;

	i = 0;
	while(i < map_info.height)
	{
		j = 0;
		while(j < map_info.width)
		{
			write(1, &map_info.grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
