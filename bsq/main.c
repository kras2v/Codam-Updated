/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:20:55 by spyun             #+#    #+#             */
/*   Updated: 2024/09/03 23:52:57 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/bsq.h"

int	main(int argc, char*argv[])
{
	int i;
	char *buffer;
	t_map_info map_info;
	
	buffer = ft_file_reader(argv[1]);
	printf("Before:\n%s", buffer);
	map_info = ft_generate_map_info(buffer);
	printf("After:\n");
	free(buffer);
	t_the_BSQ bsq = ft_find_res_area(&map_info);
	ft_mark_square(&map_info, bsq);
	ft_print_map_grid(map_info);
	return (0);
}