/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 03:54:52 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:13:03 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_str_lenght(char *str)  
{
	int	lenght;

	lenght = 0;
	while (str[lenght])
		lenght++;
	return (lenght);
}

void	ft_put_erreur(char *str)
{
	write(2, "Error\n", 6);
	write(1, &str[0], ft_str_lenght(str));
	exit(1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	index;

	index = 0;
	while (str1[index] && str2[index] && str1[index] - str2[index] == 0)
		index++;
	return (str1[index] - str2[index]);
}

static void	ft_fill_matrix2(int fd, t_maps *s_gm_maps)
{
	char	*line;
	int		row;
	int		col;

	row = 0;
	col = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (row < s_gm_maps->height)
		{
			col = 0;
			while (col < s_gm_maps->width)
			{
				s_gm_maps->maps[row][col] = line[col];
				col++;
			}
			s_gm_maps->maps[row][col] = '\0';
			row++;
			free (line);
			line = get_next_line(fd);
		}
	}
	s_gm_maps->maps[row] = NULL;
}

void	ft_fill_matrix(int fd, t_maps *s_gm_maps)
{
	int	i;

	if (s_gm_maps->width -1 > 51)
		ft_put_erreur("size map 'width' not compatible with mac screen");
	else if (s_gm_maps->height > 26)
		ft_put_erreur("size map 'height' not compatible with mac screen");
	s_gm_maps->maps = malloc(sizeof(char *) * (s_gm_maps->height + 1));
	if (!s_gm_maps->maps)
		ft_put_erreur("malloc matrix maps heap");
	i = -1;
	while (++i < s_gm_maps->height)
	{
		s_gm_maps->maps[i] = malloc(sizeof(char ) * s_gm_maps->width + 1);
		if (!s_gm_maps->maps[i])
		{
			if (i >= 1)
			{
				while (i >= 0)
					free (s_gm_maps->maps[i--]);
				free (s_gm_maps->maps);
			}
			ft_put_erreur("malloc matrix maps heap");
		}
	}
	ft_fill_matrix2(fd, s_gm_maps);
}
