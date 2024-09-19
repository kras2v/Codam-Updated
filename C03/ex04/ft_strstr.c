/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:58:20 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/19 16:22:17 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char* str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_is_null_or_empty(char *str)
{
	return (*str == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		to_find_len;

	to_find_len = ft_strlen(to_find);
	i = 0;
	j = 0;
	if(ft_is_null_or_empty(to_find))
		return str;
	while (str[i] != '\0')
	{
		if(str[i] == to_find[j])
		{
			j++;
			if (j == to_find_len)
				return &str[i - j + 1];
		}
		else
		{
			i = i - j;
   j = 0;
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s", ft_strstr("ACBCD", "AAAAA"));
// 	return (0);
// }
