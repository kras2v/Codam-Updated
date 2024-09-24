/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:50:02 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/02 12:32:24 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_is_num(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	ft_sign(int sign_counter)
{
	if (sign_counter % 2 != 0)
		return (-1);
	return (1);
}

int	ft_is_whitespace(char ch)
{
	return ((ch >= 9 && ch <= 13)
		|| (ch == ' '));
}

long	ft_atol(char *str)
{
	long	res;
	int	minus_counter;

	res = 0;
	minus_counter = 0;
	while (ft_is_whitespace(*str))
		str++;
	while (*str == '-' || *str == '+')
		minus_counter += (*str++ == '-');
	while (ft_is_num(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= ft_sign(minus_counter);
	return (res);
}

typedef struct s_map
{
	long size;
	char em;
	char ob;
	char obs;

} t_map;


int main(int argc, char** argv)
{
	int bytes;
	int size;
	int fd1;
	t_map map;
	char *buffer;
	int i;

	buffer = malloc(100 * sizeof(char));
	i = 0;
	if(!buffer)
	{
		printf("Error (memory allocation)");
		exit(1);
	}
	fd1 = open("map.txt", O_RDONLY); //File Descriptor
	if(fd1 < 0)
	{
		printf("Error Number (open)");
		free(buffer);
		exit(1);
	}
	buffer[bytes] = '\0';
	while(i < bytes)
	{
		if(buffer[i] == '\n')
			break ;
		i++;
	}
	read(fd1, )
	printf("%s\n", buffer);
	map.size = ft_atol(buffer);
	map.em = buffer[i - 3];
	map.ob = buffer[i - 2];
	map.em = buffer[i - 1];
	printf("em : %c\n", map.em);
	if (close(fd1) < 0) 
	{
		printf("Error Number (close)");
		exit(1);
	}
}