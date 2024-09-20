/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:10:47 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/20 15:54:33 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_sign(char ch)
{
	return ((ch > 7 && ch < 13)
		|| (ch > 31 && ch < 48)
		|| (ch > 57 && ch < 64)
		|| (ch > 90 && ch < 97)
		|| (ch > 122 && ch < 127));
}

char	ft_charlowcase(char ch)
{
	if ((ch >= 'A' && ch <= 'Z'))
		return (ch += 32);
	return (ch);
}

char	ft_charupcase(char ch)
{
	if ((ch >= 'a' && ch <= 'z'))
		return (ch -= 32);
	return (ch);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	size;

	i = 1;
	size = ft_strlen(str);
	str[0] = ft_charupcase(str[0]);
	while (i < size)
	{
		if (ft_char_is_sign(str[i - 1]))
			str[i] = ft_charupcase(str[i]);
		else
			str[i] = ft_charlowcase(str[i]);
		i++;
	}
	return (str);
}
