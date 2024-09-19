/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:56:07 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/19 14:51:36 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*p_dest;
	unsigned int	i;

	p_dest = dest;
	i = 0;
	while (*p_dest)
	{
		p_dest++;
	}
	while (*src && (i < nb))
	{
		*p_dest = *src;
		p_dest++;
		src++;
		i++;
	}
	*p_dest = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char	dest[6];
// 	char	*p_dest;
// 	int		i;

// 	p_dest = "Hello";
// 	i = 0;
// 	while(*p_dest)
// 	{
// 		dest[i] = *p_dest;
// 		p_dest++;
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	printf("%s\n", dest);
// 	printf("%s\n", ft_strncat(dest, "heeeeeeei", 1));
// 	return (0);
// }