/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:47:22 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/20 16:43:55 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*p_dest;

	i = 0;
	p_dest = dest;
	while (*src && (i < n))
	{
		*p_dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*p_dest++ = '\0';
		i++;
	}
	return (dest);
}
