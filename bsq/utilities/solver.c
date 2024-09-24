/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:34:28 by spyun             #+#    #+#             */
/*   Updated: 2024/09/03 23:48:46 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_is_valid_square(int x, int y, int area, t_map_info *map_info)
{
	int	i;
	int	j;

	i = y;
	while (i <= y + area && i < map_info->height)
	{
		j = x;
		while (j <= x + area && j < map_info->width)
		{
			if (map_info->grid[i][j] == map_info->obstacle_ch)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_update_max_square(int i, int j,
						t_the_BSQ *max_square, t_map_info *map_info)
{
	int	area;

	area = 0;
	while (i + area < map_info->height && j + area < map_info->width
		&& ft_is_valid_square(j, i, area, map_info))
		area++;
	if (area > max_square->area)
	{
		max_square->area = area;
		max_square->y = i;
		max_square->x = j;
	}
}

t_the_BSQ	ft_find_res_area(t_map_info *map_info)
{
	int			i;
	int			j;
	t_the_BSQ	max_square;

	max_square.area = 0;
	max_square.y = 0;
	max_square.x = 0;
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			ft_update_max_square(i, j, &max_square, map_info);
			j++;
		}
		i++;
	}
	return (max_square);
}

void	ft_mark_square(t_map_info *map_info, t_the_BSQ square)
{
	int	i;
	int	j;

	i = square.y;
	while (i < square.y + square.area)
	{
		j = square.x;
		while (j < square.x + square.area)
		{
			map_info->grid[i][j] = map_info->full_ch;
			j++;
		}
		i++;
	}
}
