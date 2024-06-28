/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 04:12:06 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:56:59 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_wall(t_maps *s_gm_maps)
{
	int	col;

	col = -1;
	while (++col < s_gm_maps->width - 1)
	{
		if (s_gm_maps->maps[0][col] != '1'
			|| s_gm_maps->maps[s_gm_maps->height - 1][col] != '1')
		{
			ft_free_matrix(s_gm_maps->maps, NULL);
			ft_put_erreur("border maps invlaid");
		}
	}
}

static void	ft_check_maps_valid(t_maps *s_gm_maps)
{
	if (s_gm_maps->clc == 0)
	{
		ft_free_matrix(s_gm_maps->maps, NULL);
		ft_put_erreur("the map does not contain collectible 'C'");
	}
	if (s_gm_maps->ext != 1)
	{
		ft_free_matrix(s_gm_maps->maps, NULL);
		ft_put_erreur("the map must contain a single exit 'E'");
	}
	if (s_gm_maps->pst != 1)
	{
		ft_free_matrix(s_gm_maps->maps, NULL);
		ft_put_erreur("the map must contain a single personage 'P'");
	}
}

static void	ft_check_inside_mp(t_maps *s_g_m, int *c, int *r)
{
	while (++(*c) < s_g_m->width - 2)
	{
		if (s_g_m->maps[*r][*c] != '0' && s_g_m->maps[*r][*c] != '1'
			&& s_g_m->maps[*r][*c] != 'C'
			&& s_g_m->maps[*r][*c] != 'E'
			&& s_g_m->maps[*r][*c] != 'P')
		{
			ft_free_matrix(s_g_m->maps, NULL);
			ft_put_erreur("there is an extraneous element in the map");
		}
		else if (s_g_m->maps[*r][*c] == 'C')
					s_g_m->clc++;
		else if (s_g_m->maps[*r][*c] == 'E')
		{
			s_g_m->col_exit = *c;
			s_g_m->row_exit = *r;
			s_g_m->ext++;
		}
		else if (s_g_m->maps[*r][*c] == 'P')
		{
			s_g_m->col_p = *c;
			s_g_m->row_p = *r;
			s_g_m->pst++;
		}
	}
}

static void	ft_check_element_maps_2(t_maps *s_gm_maps)
{
	int	row;
	int	col;

	row = 1;
	while (row < s_gm_maps->height - 1)
	{
		col = 0;
		if (s_gm_maps->maps[row][0] != '1')
		{
			ft_free_matrix(s_gm_maps->maps, NULL);
			ft_put_erreur("border maps invlaid");
		}
		ft_check_inside_mp(s_gm_maps, &col, &row);
		if (s_gm_maps->maps[row][s_gm_maps->width - 2] != '1')
		{
			ft_free_matrix(s_gm_maps->maps, NULL);
			ft_put_erreur("borders maps invlaid");
		}
		row++;
	}
}

void	ft_check_element_maps(t_maps *s_gm_maps)
{
	s_gm_maps->pst = 0;
	s_gm_maps->clc = 0;
	s_gm_maps->ext = 0;
	ft_check_wall(s_gm_maps);
	ft_check_element_maps_2(s_gm_maps);
	ft_check_maps_valid(s_gm_maps);
}
