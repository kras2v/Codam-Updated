/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:58:20 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/20 23:04:43 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!to_find[j])
		return (str);
	while (str[i])
	{
		if (j != 0)
			i = i - j;
		j = 0;
		while (str[i] == to_find[j])
		{
			i++;
			if (!to_find[++j])
				return (&str[i - j]);
		}
		i++;
	}
	return (0);
}
