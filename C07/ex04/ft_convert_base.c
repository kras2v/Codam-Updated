/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:19:06 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/29 10:04:58 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base_to_dec(char *str, char *base);

int	ft_strlen(char *base)
{
	int	len;

	len = 0;
	while (*base++)
		len++;
	return (len);
}

int	ft_is_base_invalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (((i != j) && (base[i] == base[j]))
				|| (base[j] == '-' || base[j] == '+')
				|| (base[j] >= 9 && base[j] <= 13)
				|| (base[j] == ' '))
				return (1);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}

void	ft_dec_to_base(int nbr, char *base, char **res, int base_len)
{
	long	nbl;

	nbl = nbr;
	if ((nbr < 0))
	{
		nbl = nbl * (-1);
		**res = '-';
		(*res)++;
	}
	if (nbl >= base_len)
	{
		ft_dec_to_base((int)(nbl / base_len), base, res, base_len);
	}
	**res = base[nbl % base_len];
	(*res)++;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	char	*res;
	char	*p_res;

	dec = 0;
	res = malloc(34 * sizeof(char));
	if ((!res)
		|| (ft_is_base_invalid(base_from) || ft_is_base_invalid(base_to)))
		return (0);
	p_res = res;
	dec = ft_atoi_base_to_dec(nbr, base_from);
	ft_dec_to_base(dec, base_to, &res, ft_strlen(base_to));
	*res = '\0';
	return (p_res);
}

// int	main(void)
// {
// 	char	*res;

// 	res = ft_convert_base("   +-+-+----10", "0123456789ABCDEF", "01");
// 	if (!res)
// 	{
// 		printf("%s", res);
// 		return (1);
// 	}
// 	printf("%s", res);
// 	return (0);
// }
