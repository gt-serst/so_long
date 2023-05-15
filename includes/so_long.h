/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:26:57 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/15 17:19:14 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <../libft/libft.h>

char	**ft_parsing(char *argv);
int		ft_open_fd(char *argv);
int		ft_count_lines(char *argv);
char	**ft_delete_nl(char **matrix);
int		ft_count_rows(char **matrix);
int		ft_check_length(char **matrix);
int		ft_check_width(char **matrix);
int		ft_get_nb_of_components(char **matrix);
void	ft_get_player_position(char **matrix);
void	ft_free_arr(char **arr);
void	ft_exit(char **matrix, char *msg);
void	ft_print_matrix(char **matrix);

#endif
