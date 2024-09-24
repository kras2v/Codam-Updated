/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:34:25 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/21 00:06:12 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

