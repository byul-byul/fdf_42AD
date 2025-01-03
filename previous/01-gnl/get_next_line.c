/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:49 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/18 17:28:36 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clean_buff(char **buff)
{
	size_t	sublen;
	char	*cleaned;
	char	*pos;

	pos = ft_strchr(*buff, SEPARATOR);
	if (!pos)
	{
		free(*buff);
		*buff = NULL;
		return ;
	}
	sublen = pos - *buff + 1;
	if ((*buff)[sublen] == '\0')
	{
		free(*buff);
		*buff = NULL;
		return ;
	}
	cleaned = ft_substr(*buff, sublen, ft_strlen(pos));
	free (*buff);
	*buff = cleaned;
}

static char	*form_next_line(char *buff)
{
	size_t	len;
	char	*pos;

	pos = ft_strchr(buff, SEPARATOR);
	if (pos)
		len = pos - buff + 1;
	else
		len = ft_strlen(buff);
	return (ft_substr(buff, 0, len));
}

static char	*read_next_line(char *line, int fd)
{
	char	*buff;
	char	*tmp;
	int		read_bytes;

	read_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(line), line = NULL, NULL);
	buff[0] = '\0';
	while (read_bytes > 0 && !ft_strchr(line, SEPARATOR))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buff[read_bytes] = '\0';
			tmp = line;
			line = ft_strjoin(line, buff);
			free(tmp);
		}
	}
	free(buff);
	if (read_bytes < 0 || !line)
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buff || !ft_strchr(buff, SEPARATOR))
		buff = read_next_line(buff, fd);
	if (!buff)
		return (NULL);
	line = form_next_line(buff);
	if (!line || ft_strlen(line) == 0)
		return (free(buff), buff = NULL, free(line), NULL);
	clean_buff(&(buff));
	return (line);
}
