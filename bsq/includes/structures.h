/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:51:36 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/03 23:39:05 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_map_info
{
	int		height;
	int		width;
	char	empty_ch;
	char	obstacle_ch;
	char	full_ch;
	char	**grid;
}	t_map_info;

typedef struct s_the_BSQ
{
	int	x;
	int	y;
	int	area;
}	t_the_BSQ;

#endif