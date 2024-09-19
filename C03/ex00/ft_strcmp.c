/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:09:20 by kvalerii          #+#    #+#             */
/*   Updated: 2024/08/19 13:59:06 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", ft_strcmp("ABC", "ABC"));
// 	printf("%d\n", ft_strcmp("AB", "ABC"));
// 	printf("%d\n", ft_strcmp("ABC", "AB"));
// 	return (0);
// }
