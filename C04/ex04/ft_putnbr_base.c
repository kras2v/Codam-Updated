/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:12:56 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/28 19:07:17 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	len;

	len = 0;
	while (*base++)
		len++;
	return (len);
}

void	ft_write_nbr_base(char *res, int index)
{
	while (index >= 0)
		write(1, &res[index--], 1);
}

int	ft_is_sign(char ch)
{
	return (ch == '-' || ch == '+');
}

int	ft_is_invalid(char *arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (((i != j) && (arr[i] == arr[j])) || ft_is_sign(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	int		is_negative;
	int		rem;
	char	res[34];
	int		i;

	i = 0;
	is_negative = (nbr < 0);
	base_len = ft_strlen(base);
	if (!ft_is_invalid(base) && base_len > 1)
	{
		if (nbr == 0)
			res[i++] = base[0];
		while (nbr != 0)
		{
			rem = nbr % base_len;
			res[i++] = base[rem * (1 - 2 * (rem < 0))];
			nbr /= base_len;
		}
		if (is_negative)
			res[i++] = '-';
		res[i] = '\0';
		ft_write_nbr_base(res, --i);
	}
}

// int	main(void)
// {
// 	ft_putnbr_base(123, "");
// 	return (0);
// }
