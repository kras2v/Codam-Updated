/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:12:54 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/25 21:22:31 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str)
	{
		ft_putstr((*par).str);
		ft_putnbr((*par).size);
		write(1, "\n", 1);
		ft_putstr((*par).copy);
		par++;
	}
}
