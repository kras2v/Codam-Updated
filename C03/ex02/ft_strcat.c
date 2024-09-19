/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:31:02 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/19 13:57:50 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*p_dest;

	p_dest = dest;
	while(*p_dest)
	{
		p_dest++;
	}
	while(*src)
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
// 	char	dest[20];
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
// 	printf("%s\n", ft_strcat(dest, "hiiiii"));
// 	return (0);
// }
