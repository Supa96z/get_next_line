/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:18:34 by abataill          #+#    #+#             */
/*   Updated: 2022/11/29 07:27:08 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n' && s[i])
		i++;
	return (i);
}

char	*next_line(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = line_len(s);
	j = 0;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	str = malloc(ft_strlen(s) - i + 1);
	if (!str)
	{
		free(s);
		return (0);
	}
	while (s[i])
		str[j++] = s[i++];
	str[j] = 0;
	free(s);
	return (str);
}

char	*cpy_buf(char *s, int fd)
{
	char	*buf;
	int		j;

	j = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!ft_strchr(s, '\n') && j)
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (j == -1)
		{
			free(buf);
			return (0);
		}
		buf[j] = 0;
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*cpy_line(char *s)
{
	int		i;
	char	*line;

	i = -1;
	if (!*s)
		return (0);
	line = malloc(line_len(s) + 1);
	if (!line)
		return (0);
	while (s[++i] != '\n' && s[i])
		line[i] = s[i];
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	s = cpy_buf(s, fd);
	if (!s)
		return (0);
	line = cpy_line(s);
	s = next_line(s);
	return (line);
}
