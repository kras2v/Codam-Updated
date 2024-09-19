/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_print_comb.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: kvalerii <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/08/13 11:37:44 by kvalerii		  #+#	#+#			 */
/*   Updated: 2024/08/14 11:54:14 by kvalerii		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_sign(int num1)
{
	if (num1 != 7)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

char	ft_int_to_char(int num)
{
	char	c;

	c = num + '0';
	return (c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int num1, int num2, int num3)
{
	ft_putchar(ft_int_to_char(num1));
	ft_putchar(ft_int_to_char(num2));
	ft_putchar(ft_int_to_char(num3));
	ft_print_sign(num1);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_print(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
