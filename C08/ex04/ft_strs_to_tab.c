/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmzvr <rmzvr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:53:22 by kvalerii          #+#    #+#             */
/*   Updated: 2024/09/25 21:22:20 by rmzvr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src, int src_size)
{
	char	*dest;
	char	*p_dest;

	dest = malloc((src_size + 1) * sizeof(char));
	if (!dest)
		return (0);
	p_dest = dest;
	while (*src)
	{
		*p_dest = *src;
		p_dest++;
		src++;
	}
	*p_dest = '\0';
	return (dest);
}

struct s_stock_str	set_value(char *av)
{
	t_stock_str	temp_stock;

	temp_stock.size = ft_strlen(av);
	temp_stock.str = av;
	temp_stock.copy = ft_strdup(av, temp_stock.size);
	return (temp_stock);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char *av[])
{
	t_stock_str	*stock_arr;
	t_stock_str	temp_stock;
	int			i;

	stock_arr = malloc((sizeof(t_stock_str) * (ac + 1)));
	if (!stock_arr)
		return (0);
	i = 0;
	while (i < ac)
	{
		temp_stock = set_value(av[i]);
		stock_arr[i] = temp_stock;
		i++;
	}
	temp_stock.str = 0;
	stock_arr[i] = temp_stock;
	return (stock_arr);
}

// void	ft_show_tab(struct s_stock_str *par);

// int	main(int argc, char *argv[])
// {
// 	struct s_stock_str *arr;

// 	if(argc > 1)
//  {
// 		arr = ft_strs_to_tab(argc, argv);
// 		ft_show_tab(arr);
// 	}
// 	return (0);
// }