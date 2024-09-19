/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:34:25 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/29 15:27:20 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (min >= max)
		return (0);
	range = malloc((size) * sizeof(int));
	if (!range)
		return (0);
	while (i < size)
	{
		range[i] = min;
		min++;
		i++;
	}
	return (range);
}

int	main(void)
{
	int	*range;
	int	i;
	int	min;
	int	max;

	min = 1;
	max = 5;
	range = ft_range(15, 10);
	i = 0;
	if(!range)
	{
		printf("NULL");
		return (1);
	}
	while(i < max - 1)
	{
		printf("%d ", range[i]);
		i++;
	}
	free(range);
	return (0);
}
