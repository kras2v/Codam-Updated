/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:07:00 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/29 10:08:02 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
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

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*p_dest;

	dest = malloc(ft_strlen(src) * sizeof(char) + 1);
	p_dest = dest;
	while (*src)
	{
		*p_dest = *src;
		p_dest++;
		src++;
	}
	*p_dest = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char *str;
// 	char *dest;

// 	str = "Hello";
// 	dest = ft_strdup("Hello");
// 	printf("%s", dest);
// 	free(dest);
// 	return (0);
// }