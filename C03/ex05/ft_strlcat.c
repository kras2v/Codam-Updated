/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:34:14 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/19 16:22:33 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(*str++)
	{
		len++;
	}
	return (len);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;
	int				res;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if(size <= dest_len)
		return size + src_len;
	else
		res = dest_len + src_len;
	i = 0; 
	while (*dest)
	{
		dest++;
	}
	while (*src && (i < size - dest_len - 1))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (res);
}

// int	main(void)
// {
// 	char a[10] = "He";
// 	printf("%d", ft_strlcat(a, "Worl", 13));
// 	return (0);
// }

