/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:34:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/29 10:06:55 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	return (dest);
}

int	ft_calc_res_size(int size, char **strs, char *sep)
{
	int	res_str_len;
	int	i;

	res_str_len = 0;
	i = 0;
	while (i < size)
	{
		res_str_len += ft_strlen(strs[i]);
		i++;
	}
	res_str_len += ft_strlen(sep) * size + 1;
	return (res_str_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		res_str_len;
	char	*res;
	char	*p_res;
	int		i;

	res_str_len = ft_calc_res_size(size, strs, sep);
	res = malloc((res_str_len) * sizeof(char));
	p_res = res;
	i = 0;
	while (i < size)
	{
		p_res = ft_strcat(p_res, strs[i]);
		if (i != size - 1)
			p_res = ft_strcat(p_res, sep);
		i++;
	}
	*p_res = '\0';
	return (res);
}

// int	main(void)
// {
// 	char *a[] = {"hel", "lo", "wo", "rl", "d"};
// 	printf("%s", ft_strjoin(5, a, "421421"));
// 	return (0);
// }