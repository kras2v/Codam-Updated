/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:05:39 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/20 15:35:45 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char *argv[])
{
	char	buffer[1];
	int		fd;
	int		bytes;

	if (argc == 1)
		ft_putstr("File name missing.");
	else if (argc > 2)
		ft_putstr("Too many arguments.");
	else
	{
		fd = open(argv[1], 1);
		while ((bytes = read(fd, buffer, sizeof(buffer))) > 0)
			ft_putstr(buffer);
		if (bytes < 0)
			ft_putstr("Cannot read file.");
		close(fd);
	}
	return (0);
}
