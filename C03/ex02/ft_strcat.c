/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:31:02 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/20 23:04:55 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*p_dest;

	p_dest = dest;
	while (*p_dest)
		p_dest++;
	while (*src)
	{
		*p_dest = *src;
		p_dest++;
		src++;
	}
	*p_dest = '\0';
	return (dest);
}
