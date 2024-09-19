/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:57:18 by valeriia          #+#    #+#             */
/*   Updated: 2024/08/25 21:36:10 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_01_H
# define RUSH_01_H
# include <unistd.h>
# include <stdlib.h>

extern int	ft_is_solved(int *grid[]);
int			ft_is_num_allowed(int *grid[], int row, int col, int num);
void		ft_print_grid(int *grid[]);
int			ft_arrcmp(int *arr1, int *arr2);
int			ft_find_the_solution(int *grid[], int row, int col, int *solved);
int			ft_is_input_format_correct(char *argv);
int			ft_is_input_no_duplicate(char *argv);
int			ft_is_four_duplicated_in_row(char *argv);
int			ft_is_string_valid(char *argv);
int			ft_is_input_valid(int argc, char *argv[]);
void		ft_split_the_input(char *argv, int start_i, int *arr);
int			ft_is_one_on_corners(int *arr_1, int *arr_2, int i_1, int i_2);
int			ft_is_sum_within_limit(int *arr_1, int *arr_2);
extern int	ft_are_values_valid(char *argv);
void		ft_initialize_grid_with_zeros(int *grid[]);
void		ft_free_grid(int **grid);
int			**ft_allocate_grid(void);
void		ft_calc_up(int *grid[], int *p_arr);
void		ft_calc_down(int *grid[], int *p_arr);
void		ft_calc_left(int *grid[], int *p_arr);
void		ft_calc_right(int *grid[], int *p_arr);

#endif
