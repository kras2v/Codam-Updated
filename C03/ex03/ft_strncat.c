/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:56:07 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/20 17:35:08 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*p_dest;
	unsigned int	i;

	p_dest = dest;
	i = 0;
	while (*p_dest)
		p_dest++;
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
