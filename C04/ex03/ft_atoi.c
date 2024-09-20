/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 10:49:18 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/20 23:36:20 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_num(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	ft_sign(int sign_counter)
{
	if (sign_counter % 2 != 0)
		return (-1);
	return (1);
}

int	ft_is_whitespace(char ch)
{
	return ((ch >= 9 && ch <= 13)
		|| (ch == ' '));
}

int	ft_atoi(char *str)
{
	int	res;
	int	minus_counter;

	res = 0;
	minus_counter = 0;
	while (ft_is_whitespace(*str))
		str++;
	while (*str == '-' || *str == '+')
		minus_counter += (*str++ == '-');
	while (ft_is_num(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= ft_sign(minus_counter);
	return (res);
}
