/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:33:56 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:04:47 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_validate_2(int fd, char *line, t_maps *s_gm_maps)
{
	s_gm_maps->tmp = 1;
	while (line != NULL)
	{
		if (ft_findnl(line) == 0)
		{
			s_gm_maps->width--;
			s_gm_maps->tmp = 0;
		}
		if (s_gm_maps->width != ft_str_lenght(line)
			|| ft_strcmp(line, "\n") == 0)
		{
			free (line);
			close(fd);
			ft_put_erreur("the width of the map invalid");
		}
		free (line);
		s_gm_maps->height++;
		line = get_next_line(fd);
	}
}

static void	ft_check_validate(int fd, char *str, t_maps *s_gm_maps)
{
	char	*line;

	s_gm_maps->height = 0;
	line = get_next_line(fd);
	if (line == NULL)
		ft_put_erreur("map empty");
	s_gm_maps->width = ft_str_lenght(line);
	if (s_gm_maps->width <= 2)
	{
		close (fd);
		ft_put_erreur("the width of the map invalid");
	}
	ft_check_validate_2(fd, line, s_gm_maps);
	if (s_gm_maps->height <= 2)
	{
		close (fd);
		ft_put_erreur("the height of the map invalid");
	}
	close (fd);
	fd = open (str, O_RDONLY);
	if (s_gm_maps->tmp == 0)
	++s_gm_maps->width;
	ft_fill_matrix(fd, s_gm_maps);
}

static void	ft_check_dimensions_and_fill_matrix(char *str, t_maps *s_gm_maps)
{
	int	fd;

	fd = open (str, O_RDONLY);
	if (fd == -1)
		ft_put_erreur("openfile , check the path or name of the file");
	else
		ft_check_validate(fd, str, s_gm_maps);
}

static void	ft_check_format(char *str)
{
	char	*format;
	int		lenght_str;

	lenght_str = ft_str_lenght(str) - 1;
	format = &str[lenght_str - 3];
	if (lenght_str < 3 || ft_strcmp (format, ".ber") != 0)
		ft_put_erreur("format file invalid");
}

int	main(int ac, char **av)
{
	t_maps		s_gm_maps;

	if (ac == 2)
	{
		ft_check_format(av[1]);
		ft_check_dimensions_and_fill_matrix(av[1], &s_gm_maps);
		ft_check_element_maps(&s_gm_maps);
		ft_check_player_path(&s_gm_maps);
		ft_creat_window(&s_gm_maps);
		ft_initialize_void_img_with_null(&s_gm_maps);
		ft_image_manipulation(&s_gm_maps);
		ft_put_img(&s_gm_maps, 'R', 'C');
		mlx_key_hook(s_gm_maps.win, ft_event_key, &s_gm_maps);
		mlx_hook(s_gm_maps.win, 17, 1L << 17, &ft_handle_close, &s_gm_maps);
		mlx_loop(s_gm_maps.mlx);
	}
	else if (ac > 2)
		ft_put_erreur("the program takes the file path of the .ber map alone");
	else
		ft_put_erreur("the program takes the file path of the .ber map");
	return (0);
}
