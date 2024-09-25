/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:23:29 by rmzvr             #+#    #+#             */
/*   Updated: 2024/09/25 23:23:30 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	while(*charset)
	{
		if(*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int word_count;

	word_count = 0;
	while(*str)
	{
		if(!ft_is_charset(*str, charset))
			word_count++;
		while(!ft_is_charset(*str, charset) && *(str + 1))
			str++;
		str++;
	}
	return (word_count);
}

int	ft_count_word_len(char *str, char *charset)
{
	int	word_len;

	word_len = 0;
	while(*str && !ft_is_charset(*str, charset))
	{
		word_len++;
		str++;
	}
	return (word_len);
}

char	*ft_write_in_res(char *str, char *res, char *charset)
{
	char *p_res;

	p_res = res;
	while(*str && !ft_is_charset(*str, charset))
	{
		*p_res = *str;
		p_res++;
		str++;
	}
	*p_res = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		word_count;
	int		word_len;

	word_count = ft_count_words(str, charset);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if(!res)
		return (0);
	i = 0;
	while (*str)
	{
		while (ft_is_charset(*str, charset))
			str++;
		word_len = ft_count_word_len(str, charset);
		if(word_len != 0)
		{
			res[i] = (char *)malloc((word_len + 1) * sizeof(char));
			res[i] = ft_write_in_res(str, res[i], charset);
			i++;
		}
		while (*str && !ft_is_charset(*str, charset))
			str++;
	}
	res[i] = 0;
	return res;
}
