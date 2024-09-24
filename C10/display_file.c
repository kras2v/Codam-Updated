/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:05:39 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/20 16:09:17 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_is_error(int argc)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.");
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	buffer[1];
	int		fd;
	int		bytes;

	if (ft_is_error(argc))
		return(1);
	else
	{
		fd = open(argv[1], 1);
		bytes = read(fd, buffer, sizeof(buffer));
		while (bytes > 0)
		{
			ft_putstr(buffer);
			bytes = read(fd, buffer, sizeof(buffer));
		}
		if (bytes < 0)
		{
			close(fd);
			ft_putstr("Cannot read file.");
			return(1);
		}
		close(fd);
	}
	return (0);
}
