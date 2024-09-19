/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:13:48 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/18 23:00:40 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	is_end(char *str, int len)
{
	int	i;

	i = 0;
	if (str[len - 1] != '9')
		return (0);
	while (i < len - 1)
	{
		if (str[i] + 1 != str[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print(char *str, int str_len, int i)
{
	write(1, str, str_len);
	write(1, ", ", 2);
	str[i]++;
}

void	ft_combination(char *str)
{
	int	str_len;
	int	i;

	str_len = ft_strlen(str);
	i = str_len - 1;
	while (!is_end(str, str_len))
	{
		if (str[i] + 1 <= '9' + 1)
			ft_print(str, str_len, i);
		else
		{
			while (str[i] == str[i - 1] + 1)
				i--;
			if (str[i] == '9' + 1)
				i--;
			if (str[i] + 1 <= '9' + 1)
				str[i]++;
			while (i != str_len - 1)
			{
				i++;
				str[i] = str[i - 1] + 1;
			}
		}
	}
	write(1, str, str_len);
}

void	ft_print_combn(int n)
{
	char	str[9];
	int		i;

	i = 0;
	while (i < n)
	{
		str[i] = i + '0';
		i++;
	}
	str[i] = '\0';
	ft_combination(str);
}
