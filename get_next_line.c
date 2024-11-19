/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:46:34 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/19 17:24:45 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE +1];
	char		res;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
		return (NULL);
	}
	res = 0;
	while (buffer[0] || 0 < read(fd, buffer, BUFFER_SIZE))
	{
		res = aux_strjoin(res, buffer);
		if (!res)
			return (NULL);
		aux_buffer_clean(buffer);
		if (res[aux_len(res) -1] == '\n')
			return (res);
	}
	return (res);
}
