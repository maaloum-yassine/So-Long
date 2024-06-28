/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 03:13:02 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:07:40 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*ft_clean_static(char *s_static)
{
	int		i;
	char	*n_static;
	char	*len;

	len = s_static;
	i = 0;
	while (s_static[i] != '\n' && s_static[i] != '\0')
	{
		len++;
		i++;
	}
	if (s_static[i] == '\n')
		i++;
	n_static = ft_substr(s_static, i, ft_strlen(len));
	free (s_static);
	s_static = n_static;
	return (s_static);
}

char	*ft_findline(char *s_static)
{
	char	*swap;
	int		i;

	i = 0;
	while (s_static[i] != '\0' && s_static[i] != '\n')
		i++;
	if (s_static[i] == '\n')
		i++;
	swap = ft_substr(s_static, 0, i);
	return (swap);
}

char	*ft_checkline(int fd, char *s_static)
{
	char	*swap;
	char	*buf;
	int		ret;

	ret = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (ret != 0 && ft_findnl(buf) == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(s_static);
			free (buf);
			return (NULL);
		}
		buf[ret] = '\0';
		swap = ft_strjoin(s_static, buf);
		free(s_static);
		s_static = swap;
	}
	free (buf);
	return (swap);
}

char	*get_next_line(int fd)
{
	static char	*s_static;
	char		*line;

	line = NULL;
	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE < 0)
	{
		return (NULL);
	}
	s_static = ft_checkline(fd, s_static);
	if (s_static == NULL)
		return (NULL);
	if (s_static[0] == '\0')
	{
		free (s_static);
		s_static = NULL;
		return (NULL);
	}
	line = ft_findline(s_static);
	s_static = ft_clean_static(s_static);
	return (line);
}
