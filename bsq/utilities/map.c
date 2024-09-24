/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 21:04:24 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/03 22:06:33 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	ft_find_the_map_height(char *buffer, int i, t_map_info *map_info)
{
	char *height_str;

	height_str = (char *)malloc((i - 3 + 1)* sizeof(char));
	if(!height_str)
		ft_raise_error_and_quit("Error allocating memory\n");
	height_str[i - 3] = '\0';
	ft_strncpy(height_str, buffer, (i - 2));
	map_info->height = ft_atoi(height_str);
}

void	ft_find_the_map_width(char *buffer, int i, t_map_info *map_info)
{
	int	map_width;

	map_width = 0;
	while(buffer[i++] != '\0')
	{
		if(buffer[i] == '\n')
			break ;
		map_width++;
	}
	map_info->width = map_width;
}

void	ft_fill_the_characters(char *buffer, int i, t_map_info *map_info)
{
	map_info->full_ch = buffer[i - 1];
	map_info->obstacle_ch = buffer[i - 2];
	map_info->empty_ch = buffer[i - 3];
}

int ft_find_first_line_end(char *buffer)
{
	int	i;
	
	i = 0;
	while(buffer[i] != '\0')
	{
		if(buffer[i] == '\n')
			break;
		i++;
	}
	return (i);
}

t_map_info ft_generate_map_info(char *buffer)
{
	int	i;
	t_map_info map_info;

	i = ft_find_first_line_end(buffer);
	ft_fill_the_characters(buffer, i, &map_info);
	ft_find_the_map_height(buffer, i, &map_info);
	ft_find_the_map_width(buffer, i, &map_info);
	ft_fill_the_grid(buffer, i, &map_info);
	return map_info;
}