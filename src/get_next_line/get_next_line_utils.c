/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:28:38 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 06:07:51 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_findnl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char *s_static, char *buf)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s_static == NULL)
	{
		s_static = "";
	}
	s = malloc(ft_strlen(s_static) + ft_strlen(buf)+1);
	if (!s)
		return (NULL);
	while (s_static[i])
	{
		s[i] = s_static[i];
		i++;
	}
	while (buf[j])
		s[i++] = buf[j++];
	s[i] = '\0';
	s_static = NULL;
	free(s_static);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
