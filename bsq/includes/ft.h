/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:52:53 by valeriia          #+#    #+#             */
/*   Updated: 2024/09/03 23:51:40 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void		ft_raise_error_and_quit(char *err_mes);
char		*ft_file_reader(char *filename);
t_map_info	ft_generate_map_info(char *buffer);
int			ft_atoi(char *str);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
int			ft_find_first_line_end(char *buffer);
void		ft_fill_the_grid(char *buffer, int k, t_map_info *map_info);
void		ft_print_map_grid(t_map_info map_info);
t_the_BSQ	ft_find_res_area(t_map_info *map_info);
void		ft_mark_square(t_map_info *map_info, t_the_BSQ square);

#endif