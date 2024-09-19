/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:03:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/29 10:03:45 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int a, int pow)
{
	if (pow == 0)
		return (1);
	return (a * ft_pow(a, pow - 1));
}

int	ft_is_base_symbol(char ch, char *base)
{
	int	is_base;

	is_base = 0;
	while (*base)
	{
		if (ch == *base)
		{
			is_base = 1;
			break ;
		}
		base++;
	}
	return (is_base);
}

int	ft_base_to_dec(char *res_str, char *base, int res_str_len, int minus_count)
{
	int	res_nbr;
	int	i;
	int	value;
	int	base_len;

	res_nbr = 0;
	i = 0;
	while (base[i])
		base_len = ++i;
	i = 0;
	while (res_str[i])
	{
		value = 0;
		while (base[value])
		{
			if (res_str[i] == base[value])
				break ;
			value++;
		}
		res_nbr += value * ft_pow(base_len, res_str_len - i - 1);
		i++;
	}
	if (minus_count % 2 != 0)
		return (-res_nbr);
	return (res_nbr);
}

int	ft_atoi_base_to_dec(char *str, char *base)
{
	char	res_str[33];
	int		i;
	int		minus_counter;

	i = 0;
	minus_counter = 0;
	while ((*str >= 9 && *str <= 13)
		|| (*str == ' '))
		str++;
	while (*str == '-' || *str == '+')
		minus_counter += (*str++ == '-');
	while (ft_is_base_symbol(*str, base))
	{
		res_str[i] = *str;
		str++;
		i++;
	}
	res_str[i] = '\0';
	return (ft_base_to_dec(res_str, base, i, minus_counter));
}
