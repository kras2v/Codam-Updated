/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:41:06 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/29 10:18:24 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
	{
		(*range) = 0;
		return (0);
	}
	(*range) = malloc((size) * sizeof(int));
	if (!(*range))
		return (-1);
	while (i < size)
	{
		(*range)[i] = min++;
		i++;
	}
	return (size);
}

// int	main(void)
// {
// 	int	*range;
// 	int	i;
// 	int	min;
// 	int	max;

// 	min = 1;
// 	max = 5;
// 	ft_ultimate_range(&range, max, min);
// 	i = 0;
// 	if(!range)
// 	{
// 		printf("NULL");
// 		return (1);
// 	}
// 	while(i < max - 1)
// 	{
// 		printf("%d ", range[i]);
// 		i++;
// 	}
// 	free(range);
// 	return (0);
// }
