/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:20:53 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/03 15:44:14 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((*s1 || *s2) && (i < n))
	{
		if (*s1 > *s2)
			return (1);
		else if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_strncmp("HeloWorld", "HelloWorld", 4));
	printf("%d\n", strcmp("HeloWorld", "HelloWorld"));
	printf("%d\n", ft_strncmp("HelloWorld", "HeloWorld", 4));
	return (0);
}
