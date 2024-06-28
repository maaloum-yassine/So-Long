/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:25:26 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:07:22 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "../include/get_next_line.h"

typedef struct s_images
{
	void	*wall;
	void	*barrier;
	void	*player_l;
	void	*player_r;
	void	*coin;
	void	*exit_c;
	void	*exit_o;
	void	*back_g;
}	t_images;

typedef struct s_maps
{
	t_images	imag;
	char		**maps;
	void		*mlx;
	void		*win;
	char		*str1;
	int			height;
	int			width;
	int			tmp;
	int			pst;
	int			clc;
	int			epty;
	int			ext;
	int			col_exit;
	int			row_exit;
	int			col_p;
	int			row_p;
	int			img_width;
	int			img_height;
	int			col;
	int			row;
	char		pos;
}	t_maps;

int		ft_str_lenght(char *str);
void	ft_put_erreur(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_fill_matrix(int fd, t_maps *s_gm_maps);
void	ft_check_element_maps(t_maps *s_gm_maps);
void	ft_free_matrix(char **maps, char **matrix);
void	ft_check_player_path(t_maps *s_gm_maps);
void	ft_check_exit(char **cp_m, t_maps *s_mps);
void	ft_creat_window(t_maps	*s_gm_maps);
void	ft_initialize_void_img_with_null(t_maps	*s_m);
void	ft_image_manipulation(t_maps	*s_m);
void	ft_put_img(t_maps *s_m, char p, char d);
int		ft_event_key(int key, t_maps	*s_gm_maps);
void	ft_put_number(int num);
int		ft_handle_close(t_maps	*s_gm_maps);
void	ft_release_memory(t_maps *s_mp);
void	ft_exit_window(t_maps	*s_m);
#endif
