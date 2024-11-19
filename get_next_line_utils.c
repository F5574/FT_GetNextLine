/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:46:30 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/19 17:21:58 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*aux_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	size_t	y;
	char	*res;

	x = 0;
	res = malloc(aux_len(s1) + aux_len(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	while (s1[x])
	{
		res[x] = s1[x];
		x++;
	}
	y = 0;
	while (s2[y] != '\n')
	{
		res[x + y] = s2[y];
		y++;
	}
	if (s2[y] == '\n')
		res[x + y] = '\n';
	res[x + y + 1] = '\0';
	if (s1)
		free(s1);
	return (res);
}

size_t	aux_len(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] && str && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	return (i);
}

void	aux_buffer_clean(char *buf)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (buf[x] != '\n' && x < BUFFER_SIZE)
	{
		buf[x] = '\0';
		x++;
	}
	if (buf[x] == '\n')
	{
		buf[x] = '\0';
		x++;
		while (x < BUFFER_SIZE)
		{
			buf[y] = buf[x];
			buf[x] = '\0';
			x++;
			y++;
		}
	}
}
