/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:27:33 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/20 23:33:13 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

char	*ft_dec_to_hex(int dec)
{
	char	res[3];
	char	*p_res;
	int		j;

	res[0] = '0';
	res[1] = '0';
	j = 2;
	p_res = res;
	res[j--] = '\0';
	while (dec >= 16)
	{
		if (dec % 16 < 10)
			res[j] = '0' + dec % 16;
		else
			res[j] = 'a' + (dec % 16 - 10);
		dec /= 16;
		j--;
	}
	if (dec % 16 < 10)
		res[j] = '0' + dec % 16;
	else
		res[j] = 'a' + (dec % 16 - 10);
	return (p_res);
}

void	ft_print_memory_address(void *address)
{
	uintptr_t	addr;
	char		buffer[17];
	int			i;

	i = 0;
	addr = (uintptr_t)address;
	while (i < 17)
	{
		buffer[i] = '0';
		i++;
	}
	buffer[--i] = '\0';
	while (i >= 0)
	{
		i--;
		if ((addr & 0xF) < 10)
			buffer[i] = '0' + (addr & 0xF) % 16;
		else
			buffer[i] = 'a' + ((addr & 0xF) - 10);
		addr >>= 4;
	}
	write(1, buffer, 16);
	write(1, ": ", 2);
}

void	ft_print_line_in_hex(char *p_addr, unsigned int *i)
{
	write(1, ft_dec_to_hex(p_addr[*i]), 2);
	if (p_addr[*i] == '\0')
	{
		(*i)++;
		return ;
	}
	if (p_addr[*i] != '\0')
		(*i)++;
	while (*i % 16 != 0)
	{
		if (p_addr[*i] == '\0')
		{
			write(1, ft_dec_to_hex(p_addr[*i]), 2);
			if (*i % 2 != 0)
				write(1, " ", 1);
			break ;
		}
		write(1, ft_dec_to_hex(p_addr[*i]), 2);
		if (*i % 2 != 0)
			write(1, " ", 1);
		(*i)++;
	}
}

void	ft_print_line(char *p_addr, unsigned int *i)
{
	if (p_addr[*i] >= 32 && p_addr[*i] <= 126)
		write(1, &p_addr[*i], 1);
	else
		write(1, ".", 1);
	if (p_addr[(*i)++] == '\0')
	{
		write(1, "\n", 1);
		return ;
	}
	if (p_addr[*i] != '\0')
		(*i)++;
	while (*i % 16 != 0)
	{
		if (p_addr[(*i)++] == '\0')
		{
			write(1, ".", 1);
			break ;
		}
		if (p_addr[*i] >= 32 && p_addr[*i] <= 126)
			write(1, &p_addr[*i], 1);
		else
			write(1, ".", 1);
		(*i)++;
	}
	write(1, "\n", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	char			*p_addr;
	unsigned int	i;
	unsigned int	start;
	int				k;

	i = 0;
	p_addr = (char *)addr;
	while (i < size)
	{
		start = i;
		if (i % 16 == 0)
		{
			ft_print_memory_address((void *)&p_addr[i]);
			ft_print_line_in_hex(p_addr, &i);
			if (i % 16 != 0)
			{
				k = 16 - (i - start) - (p_addr[i - 1] != '\0');
				k = (k * 2 + (k + (k % 2 == 1)) / 2) + 1;
				while (--k > 0)
					write(1, " ", 1);
			}
			i = start;
			ft_print_line(p_addr, &i);
		}
	}
}
