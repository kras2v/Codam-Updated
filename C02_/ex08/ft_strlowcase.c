/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:27:18 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/20 15:54:23 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ch_is_uppercase(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	char	*p_str;

	p_str = str;
	while (*p_str)
	{
		if (ft_ch_is_uppercase(*p_str))
			*p_str += 32;
		p_str++;
	}
	return (str);
}
