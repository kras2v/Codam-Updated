/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:17:15 by ikhelili          #+#    #+#             */
/*   Updated: 2024/08/19 12:40:10 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c);

int	ft_str_to_num(char *str)
{
	int	num;
	int	int_max;

	num = 0;
	int_max = 2147483647;
	while (*str != '\0')
	{
		if ((*str >= '0' && *str <= '9') && (num <= int_max / 10))
		{
			num = num * 10 + (*str - '0');
			str++;
		}
		else
		{
			num = -1;
			break ;
		}
	}
	return (num);
}

int	ft_if_x_y_are_valid(int x, int y)
{
	return (x >= 1 && y >= 1);
}

void	ft_raise_error(void)
{
	ft_putchar('E');
}

// int	main(int argc, char *argv[])
// {
// 	int	x;
// 	int	y;

// 	if (argc != 3)
// 		ft_raise_error();
// 	else
// 	{
// 		x = ft_str_to_num(argv[1]);
// 		y = ft_str_to_num(argv[2]);
// 		if (ft_if_x_y_are_valid(x, y))
// 			rush(x, y);
// 		else
// 			ft_raise_error();
// 	}
// 	return (0);
// }

int	main(void)
{
	int	x;
	int	y;

	x = 42;
	y = "'fsa'";
	if (ft_if_x_y_are_valid(x, y))
		rush(x, y);
	else
		ft_raise_error();
	return (0);
}
