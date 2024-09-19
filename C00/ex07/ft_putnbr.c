/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:41:32 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/26 18:00:38 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	nbl;
	char	c;

	nbl = nb;
	if (nb < 0)
	{
		nbl = nbl * (-1);
		write(1, "-", 1);
	}
	if (nbl >= 10)
	{
		ft_putnbr(nbl / 10);
	}
	c = nbl % 10 + '0';
	write(1, &c, 1);
}

// int	main(void)
// {
// 	ft_putnbr(-2147483648);
// 	return (0);
// }
