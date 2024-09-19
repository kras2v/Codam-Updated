/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:51:57 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/18 22:57:33 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_print_num(n / 10);
	}
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_print_num_in_format(int n)
{
	if (n < 10)
		write(1, "0", 1);
	ft_print_num(n);
}

void	ft_print_comb(int i, int j)
{
	ft_print_num_in_format(i);
	write(1, " ", 1);
	ft_print_num_in_format(j);
	if (i != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_print_comb(i, j);
			j++;
		}
		i++;
	}
}
