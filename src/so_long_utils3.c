/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:29:37 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:04:36 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_path_in_inside(char **copy_maps, t_maps *s_gm_maps)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (copy_maps[row] != NULL)
	{
		col = 0;
		while (copy_maps[row][col])
		{
			if (copy_maps[row][col] == 'C')
			{
				ft_free_matrix(s_gm_maps->maps, copy_maps);
				ft_put_erreur("Player path is invalid");
			}
			col++;
		}
		row++;
	}
}

static void	ft_fill_the_map_by_p(char **c_mp, int *row, int *col, int *x)
{
	if (c_mp[*row][*col] == 'P')
	{
		if (c_mp[*row][*col + 1] == '0' || c_mp[*row][*col + 1] == 'C' )
		{
			c_mp[*row][*col + 1] = 'P';
			*x = 1;
		}
		if (c_mp[*row][*col - 1] == '0' || c_mp[*row][*col - 1] == 'C')
		{
				c_mp[*row][*col - 1] = 'P';
				*x = 1;
		}
		if (c_mp[*row + 1][*col] == '0' || c_mp[*row + 1][*col] == 'C')
		{
			c_mp[*row + 1][*col] = 'P';
			*x = 1;
		}
		if (c_mp[*row - 1][*col] == '0' || c_mp[*row - 1][*col] == 'C')
		{
			c_mp[*row - 1][*col] = 'P';
			*x = 1;
		}
	}
	(*col)++;
}

static char	**ft_fill_copy_map2(t_maps *s_gm_maps, char **s_copy_maps)
{
	int	col;
	int	row;

	row = 0;
	while (row < s_gm_maps->height)
	{
		col = 0;
		while (col < s_gm_maps->width)
		{
			s_copy_maps[row][col] = s_gm_maps->maps[row][col];
			col++;
		}
		s_copy_maps[row][col] = '\0';
		row++;
	}
	s_copy_maps[row] = NULL;
	return (s_copy_maps);
}

static char	**ft_fill_copy_map(t_maps *s_gm_maps, char **s_copy_maps)
{
	int	i;

	s_copy_maps = malloc(sizeof(char *) * (s_gm_maps->height + 1));
	if (!s_copy_maps)
	{
		ft_free_matrix(s_gm_maps->maps, NULL);
		ft_put_erreur("malloc matrix copy maps heap");
	}
	i = -1;
	while (++i < s_gm_maps->height)
	{
		s_copy_maps[i] = malloc(sizeof(char ) * s_gm_maps->width + 1);
		if (!s_copy_maps[i])
		{
			if (i >= 1)
			{
				while (i >= 0)
					free (s_copy_maps[i--]);
			}
			free (s_copy_maps);
			ft_free_matrix(s_gm_maps->maps, NULL);
			ft_put_erreur("malloc matrix copy maps heap");
		}
	}
	return (ft_fill_copy_map2(s_gm_maps, s_copy_maps));
}

void	ft_check_player_path(t_maps *s_gm_maps)
{
	char	**copy_maps;
	int		x;
	int		row;
	int		col;

	copy_maps = NULL;
	x = 1;
	copy_maps = ft_fill_copy_map(s_gm_maps, copy_maps);
	while (x)
	{
		x = 0;
		row = 1;
		while (copy_maps[row] != NULL)
		{
			col = 1;
			while (copy_maps[row][col] != '\0' && copy_maps[row][col] != '\n')
				ft_fill_the_map_by_p(copy_maps, &row, &col, &x);
			row++;
		}
	}
	ft_check_path_in_inside(copy_maps, s_gm_maps);
	ft_check_exit(copy_maps, s_gm_maps);
	ft_free_matrix(copy_maps, NULL);
}
