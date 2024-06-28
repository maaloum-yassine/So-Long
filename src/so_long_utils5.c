/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:32:09 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:04:40 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_image_upload(t_maps *s_m, void *img, int *x)
{
	mlx_put_image_to_window(s_m->mlx, s_m->win, img, *x, s_m->row * 50);
}

static void	ft_put_img_inside2(t_maps *s_m, int *x, char p, char d)
{
	if (s_m->str1[s_m->col] == '1')
		ft_image_upload(s_m, s_m->imag.barrier, x);
	else if (s_m->str1[s_m->col] == '0')
		ft_image_upload(s_m, s_m->imag.back_g, x);
	else if (s_m->str1[s_m->col] == 'C')
	{
		ft_image_upload(s_m, s_m->imag.back_g, x);
		ft_image_upload(s_m, s_m->imag.coin, x);
	}
	else if (s_m->str1[s_m->col] == 'P' && p == 'R')
	{
		ft_image_upload(s_m, s_m->imag.back_g, x);
		ft_image_upload(s_m, s_m->imag.player_r, x);
	}
	else if (s_m->str1[s_m->col] == 'P' && p == 'L')
	{
		ft_image_upload(s_m, s_m->imag.back_g, x);
		ft_image_upload(s_m, s_m->imag.player_l, x);
	}
	else if (s_m->str1[s_m->col] == 'E' && d == 'C')
		ft_image_upload(s_m, s_m->imag.exit_c, x);
	else if (s_m->str1[s_m->col] == 'E' && d == 'O')
		ft_image_upload(s_m, s_m->imag.exit_o, x);
}

static void	ft_put_img_inside(t_maps *s_maps, char p, char d)
{
	int	x;

	s_maps->row = 0;
	while (++s_maps->row < s_maps->height - 1)
	{
		x = 50;
		s_maps->col = 0;
		s_maps->str1 = s_maps->maps[s_maps->row];
		while (++s_maps->col < s_maps->width - 2)
		{
			ft_put_img_inside2(s_maps, &x, p, d);
			x += 50;
		}
	}
}

static void	ft_put_img_mur(t_maps *s_m)
{
	int	i;
	int	x;

	x = 0;
	i = -1;
	s_m->img_width = 50;
	s_m->img_height = 50;
	while (++i < s_m->width - 1)
	{
		mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->imag.wall, x, 0);
		mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->imag.wall, 0, x);
		mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->imag.wall,
			x, (s_m->height - 1) * 50);
		mlx_put_image_to_window(s_m->mlx, s_m->win, s_m->imag.wall,
			(s_m->width - 2) * 50, x);
		x += 50;
	}
}

void	ft_put_img(t_maps *s_m, char p, char d)
{
	ft_put_img_mur(s_m);
	ft_put_img_inside(s_m, p, d);
}
