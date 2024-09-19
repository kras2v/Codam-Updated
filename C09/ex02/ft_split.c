/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:32:27 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/03 13:59:17 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_any(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c || c == '\0')
			return (1);
		charset++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (count == 0 && !ft_any(*str, charset))
			count++;
		if (ft_any(*str, charset) && !ft_any(*(str + 1), charset))
			count++;
		str++;
	}
	return (count);
}

int	ft_count_word_len(char **str, char *charset)
{
	int	word_len;

	word_len = 0;
	while (!ft_any(**str, charset))
	{
		if (!(**str))
			break ;
		word_len++;
		(*str)++;
	}
	return (word_len);
}

void	ft_write_into_res(char **str, char *charset, char **res, int word_len)
{
	while (!ft_any(**str, charset))
	{
		if (!(*str))
			break ;
		**res = **str;
		(*res)++;
		(*str)++;
	}
	if (word_len != 0)
	{
		**res = '\0';
		(*res) -= word_len;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		word_len;
	int		i;

	i = 0;
	res = malloc((ft_word_count(str, charset) + 1) * sizeof(char *));
	if (!res)
		return (0);
	while (*str)
	{
		if (ft_any(*str, charset))
			str++;
		word_len = ft_count_word_len(&str, charset);
		str -= word_len;
		if (word_len != 0)
			res[i] = malloc((word_len + 1) * sizeof(char));
		ft_write_into_res(&str, charset, &(res[i]), word_len);
		if (word_len != 0)
		{
			i++;
		}
	}
	res[i] = 0;
	return (res);
}

int	main(void)
{
	char	**res;
	int		i;

	res = ft_split("abc as \nu", " 1\t\n");
	i = 0;
	while (res[i] != NULL)
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);	
	return (0);
}
