/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:59:15 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:04:42 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_change_position_player(t_maps *s_m)
{
	if (s_m->pos == 'r')
	{
		s_m->maps[s_m->row_p][s_m->col_p + 1] = 'P';
		s_m->maps[s_m->row_p][s_m->col_p] = '0';
		s_m->col_p++;
	}
	else if (s_m->pos == 'l')
	{
		s_m->maps[s_m->row_p][s_m->col_p - 1] = 'P';
		s_m->maps[s_m->row_p][s_m->col_p] = '0';
		s_m->col_p--;
	}
	else if (s_m->pos == 't')
	{
		s_m->maps[s_m->row_p - 1][s_m->col_p] = 'P';
		s_m->maps[s_m->row_p][s_m->col_p] = '0';
		s_m->row_p--;
	}
	else if (s_m->pos == 'b')
	{
		s_m->maps[s_m->row_p + 1][s_m->col_p] = 'P';
		s_m->maps[s_m->row_p][s_m->col_p] = '0';
		s_m->row_p++;
	}
}

static void	ft_put_win(t_maps	*s_m, int *p_left)
{
	if (s_m->clc == 0 && *p_left == -1)
		ft_put_img(s_m, 'L', 'O');
	else if (s_m->clc == 0 && *p_left == 0)
		ft_put_img(s_m, 'R', 'O');
	else if (*p_left == -1)
		ft_put_img(s_m, 'L', 'C');
	else if (*p_left == 0)
		ft_put_img(s_m, 'R', 'C');
	if (s_m->tmp == -1)
	{
		write(1, "YOU WIN\n", 8);
		ft_release_memory(s_m);
		ft_free_matrix(s_m->maps, NULL);
		exit(1);
	}
}

static void	ft_move(t_maps *s_m, char str, int *step, int *p_left)
{
	mlx_clear_window(s_m->mlx, s_m->win);
	if (str == 'E' && s_m->clc == 0)
	{
		ft_change_position_player(s_m);
		s_m->tmp = -1;
		ft_put_number(++(*step));
		write(1, "\n", 1);
	}
	else if (str != '1' && str != 'E')
	{
		if (str == 'C')
			s_m->clc--;
		ft_change_position_player(s_m);
		ft_put_number(++(*step));
		write(1, "\n", 1);
	}
	ft_put_win(s_m, p_left);
}

static void	ft_signal_key(int key, t_maps *s_m, int *step, int *p_left)
{
	if (key == 124 || key == 2)
	{
		*p_left = 0;
		s_m->pos = 'r';
		ft_move(s_m, s_m->maps[s_m->row_p][s_m->col_p + 1], step, p_left);
	}
	else if (key == 123 || key == 0)
	{
		*p_left = -1;
		s_m->pos = 'l';
		ft_move(s_m, s_m->maps[s_m->row_p][s_m->col_p - 1], step, p_left);
	}
	else if (key == 125 || key == 1)
	{
		s_m->pos = 'b';
		ft_move(s_m, s_m->maps[s_m->row_p + 1][s_m->col_p], step, p_left);
	}
	else if (key == 126 || key == 13)
	{
		s_m->pos = 't';
		ft_move(s_m, s_m->maps[s_m->row_p -1][s_m->col_p], step, p_left);
	}
	else if (key == 53)
		ft_exit_window(s_m);
}

int	ft_event_key(int key, t_maps	*s_m)
{
	static int	step;
	static int	p_left;

	ft_signal_key(key, s_m, &step, &p_left);
	return (1);
}
