/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:13:41 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:04:38 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_exit(char **cp_m, t_maps *s_mps)
{
	int	col;
	int	row;
	int	check;

	col = s_mps->col_exit;
	row = s_mps->row_exit;
	check = 0;
	if (cp_m[row][col + 1] == 'P' || cp_m[row][col - 1] == 'P'
		|| cp_m[row + 1][col] == 'P' || cp_m[row - 1][col] == 'P')
		check = 1;
	if (check == 0)
	{
		ft_free_matrix(s_mps->maps, cp_m);
		ft_put_erreur("Player path is invalid");
	}
}

void	ft_creat_window(t_maps	*s_gm_maps)
{
	s_gm_maps->mlx = mlx_init();
	if (!s_gm_maps->mlx)
	{
		ft_free_matrix(s_gm_maps->maps, NULL);
		ft_put_erreur("the initialization of the MLX framework");
	}
	s_gm_maps->win = mlx_new_window(s_gm_maps->mlx, (s_gm_maps->width - 1) * 50,
			s_gm_maps->height * 50, "so_long");
	if (!s_gm_maps->win)
	{
		ft_free_matrix(s_gm_maps->maps, NULL);
		ft_put_erreur("Failed to create window");
	}
}

void	ft_initialize_void_img_with_null(t_maps	*s_m)
{
	s_m->imag.wall = NULL;
	s_m->imag.back_g = NULL;
	s_m->imag.coin = NULL;
	s_m->imag.barrier = NULL;
	s_m->imag.player_r = NULL;
	s_m->imag.player_l = NULL;
	s_m->imag.exit_c = NULL;
	s_m->imag.exit_o = NULL;
}

static void	ft_check_image_upload(t_maps *s_m, void *img)
{
	if (!img)
	{
		ft_release_memory(s_m);
		ft_free_matrix(s_m->maps, NULL);
		ft_put_erreur("image upload failed");
	}
}

void	ft_image_manipulation(t_maps	*s_m)
{
	s_m->imag.wall = mlx_xpm_file_to_image(s_m->mlx, "textures/wall.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.wall);
	s_m->imag.back_g = mlx_xpm_file_to_image(s_m->mlx, "textures/backg.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.back_g);
	s_m->imag.coin = mlx_xpm_file_to_image(s_m->mlx, "textures/coin.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.coin);
	s_m->imag.barrier = mlx_xpm_file_to_image(s_m->mlx, "textures/barrier.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.barrier);
	s_m->imag.player_r = mlx_xpm_file_to_image(s_m->mlx, "textures/plyer_r.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.player_r);
	s_m->imag.player_l = mlx_xpm_file_to_image(s_m->mlx, "textures/plyer_l.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.player_l);
	s_m->imag.exit_c = mlx_xpm_file_to_image(s_m->mlx, "textures/close_d.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.exit_c);
	s_m->imag.exit_o = mlx_xpm_file_to_image(s_m->mlx, "textures/open_d.xpm",
			&s_m->img_width, &s_m->img_height);
	ft_check_image_upload(s_m, s_m->imag.exit_o);
}
