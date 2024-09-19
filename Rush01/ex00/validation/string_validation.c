/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:53:23 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/25 21:06:01 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/rush_01.h"

int	ft_is_input_format_correct(char *argv)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 31;
	while (i < max_len)
	{
		if ((!(argv[i] >= '1' && argv[i] <= '4') && i % 2 == 0)
			|| (i % 2 == 1 && argv[i] != 32))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_input_no_duplicate(char *argv)
{
	int	count_arr[4];
	int	i;

	i = 0;
	count_arr[0] = 0;
	count_arr[1] = 0;
	count_arr[2] = 0;
	count_arr[3] = 0;
	while (*argv)
	{
		if (*argv == '1')
			count_arr[0]++;
		if (*argv == '2')
			count_arr[1]++;
		if (*argv == '3')
			count_arr[2]++;
		if (*argv++ == '4')
			count_arr[3]++;
	}
	while (i < 4)
	{
		if (count_arr[i++] >= 16)
			return (0);
	}
	return (1);
}

int	ft_is_four_duplicated_in_row(char *argv)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 4 * 4 * 2 - 1)
	{
		if (argv[i] == '4')
			count++;
		if (i % 8 == 0)
			count = 0;
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_string_valid(char *argv)
{
	return (ft_is_input_format_correct(argv)
		&& ft_is_input_no_duplicate(argv)
		&& !ft_is_four_duplicated_in_row(argv));
}

int	ft_is_input_valid(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (ft_is_string_valid(argv[1]))
		{
			if (ft_are_values_valid(argv[1]))
				return (1);
		}
	}
	return (0);
}
