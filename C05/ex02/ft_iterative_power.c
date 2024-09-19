/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:15:30 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/23 18:24:00 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("%d\n", ft_iterative_power(3, -1));
// 	printf("%d\n", ft_iterative_power(3, 2));
// 	printf("%d", ft_iterative_power(0, 0));

// 	return (0);
// }
