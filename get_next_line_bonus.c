/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:46:34 by gvon-ah-          #+#    #+#             */
/*   Updated: 2024/11/28 15:10:08 by gvon-ah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*res;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || FOPEN_MAX <= fd)
	{
		if (fd > 0 && FOPEN_MAX > fd)
			while (buffer[fd][i])
				buffer[fd][i++] = '\0';
		return (NULL);
	}
	res = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		res = aux_strjoin(res, buffer[fd]);
		if (!res)
			return (NULL);
		aux_buffer_clean(buffer[fd]);
		if (res[aux_len(res) - 1] == '\n')
			return (res);
	}
	return (res);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd,fd1;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	close(fd1);
	return (0);
} */
