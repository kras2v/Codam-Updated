/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:53:26 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/25 21:16:32 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/rush_01.h"

int	main(int argc, char *argv[])
{
	int	is_solved;
	int	**grid;

	is_solved = 0;
	if (ft_is_input_valid(argc, argv))
	{
		grid = ft_allocate_grid();
		ft_find_the_solution(grid, 0, 0, &is_solved);
		ft_free_grid(grid);
	}
	if (!is_solved)
		write(1, "Error\n", 6);
	return (0);
}
