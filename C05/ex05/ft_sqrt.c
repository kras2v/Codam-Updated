/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:45:23 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/20 23:46:12 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_square_exist(int a)
{
	int	last_digit;

	last_digit = a % 10;
	if (last_digit == 2
		|| last_digit == 3
		|| last_digit == 7
		|| last_digit == 8)
		return (0);
	return (1);
}

int	ft_sqrt(int nb)
{
	int	count;
	int	odd;

	count = 0;
	odd = 1;
	if (is_square_exist(nb))
	{
		while (nb > 0)
		{
			nb -= odd;
			odd += 2;
			count++;
		}
		if (nb == 0)
			return (count);
	}
	return (0);
}
