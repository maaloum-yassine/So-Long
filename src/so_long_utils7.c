/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 05:12:18 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:04:44 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_matrix(char **maps, char **matrix)
{
	int	i;

	i = 0;
	if (maps != NULL)
	{
		while (maps[i] != NULL)
			free (maps[i++]);
		free (maps);
	}
	if (matrix != NULL)
	{
		i = 0;
		while (matrix[i] != NULL)
			free (matrix[i++]);
		free (matrix);
	}
}

void	ft_put_number(int num)
{
	if (num >= 0 && num <= 9)
	{
		num += '0';
		write(1, &num, 1);
	}
	else
	{
		ft_put_number(num / 10);
		ft_put_number(num % 10);
	}
}

int	ft_handle_close(t_maps	*s_gm_maps)
{
	ft_release_memory(s_gm_maps);
	ft_free_matrix(s_gm_maps->maps, NULL);
	exit(0);
	return (0);
}

void	ft_release_memory(t_maps *s_mp)
{
	if (s_mp->imag.back_g != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.back_g);
	if (s_mp->imag.barrier != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.barrier);
	if (s_mp->imag.coin != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.coin);
	if (s_mp->imag.exit_c != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.exit_c);
	if (s_mp->imag.exit_o != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.exit_o);
	if (s_mp->imag.player_l != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.player_l);
	if (s_mp->imag.player_r != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.player_r);
	if (s_mp->imag.wall != NULL)
		mlx_destroy_image(s_mp->mlx, s_mp->imag.wall);
	mlx_destroy_window(s_mp->mlx, s_mp->win);
}

void	ft_exit_window(t_maps	*s_m)
{
	ft_release_memory(s_m);
	ft_free_matrix(s_m->maps, NULL);
	exit(0);
}
