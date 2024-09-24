/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:54:59 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/03 21:12:52 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_open_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0) {
		ft_raise_error_and_quit("Error opening file\n");
	}
	return (fd);
}

int	ft_file_size_determinator(char *filename)
{
	char temp_buffer[10];
	int total_size = 0;
	int bytes_read;
	int fd;

	fd = ft_open_file(filename);
	while ((bytes_read = read(fd, temp_buffer, sizeof(temp_buffer))) > 0)
		total_size += bytes_read;
	if (bytes_read < 0) {
		close(fd);
		ft_raise_error_and_quit("Error reading file\n");
	}
	close(fd);
	return (total_size);
}

char	*ft_file_reader(char *filename)
{
	char	*buffer;
	int		total_size;
	int		fd;

	total_size = ft_file_size_determinator(filename);
	buffer = (char *)malloc(total_size + 1);
	if (!buffer) {
		ft_raise_error_and_quit("Error allocating memory\n");
		return (0);
	}
	fd = ft_open_file(filename);
	total_size = read(fd, buffer, total_size);
	if (!buffer)
		ft_raise_error_and_quit("Failed to read the file.\n");
	buffer[total_size] = '\0';
	return (buffer);
}
