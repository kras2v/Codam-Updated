/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:55:01 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/17 13:04:57 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_hex(int i, char *hex)
{
	if (i == 1)
	{
		hex[i] = '0';
		hex[++i] = '\\';
		hex[++i] = '\0';
	}
	else
	{
		hex[i] = '\\';
		hex[++i] = '\0';
	}
	while (--i >= 0)
	{
		write(1, &hex[i], 1);
	}
}

void	ft_dec_to_hex(int dec)
{
	int		temp;
	char	hex[100];
	int		i;

	i = 0;
	while (dec != 0)
	{
		temp = dec % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 87;
		hex[i++] = temp;
		dec = dec / 16;
	}
	ft_write_hex(i, hex);
}

int	ft_ch_is_non_printable(char ch)
{
	return ((ch >= 0 && ch <= 31) || ch == 127);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_ch_is_non_printable(*str))
		{
			ft_dec_to_hex(*str);
			str++;
		}
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	return (0);
}
