/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abataill <abataill@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:18:43 by abataill          #+#    #+#             */
/*   Updated: 2022/11/24 01:26:26 by abataill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*s3;

	s3 = 0;
	i = -1;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
	{
		free(s1);
		return (0);
	}
	while (s1[++i])
		s3[i] = s1[i];
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = 0;
	free(s1);
	return (s3);
}

char	*ft_strchr(char *s, char c)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(s);
	while (++i < j)
		if (s[i] == c)
			return (s + i);
	return (0);
}
