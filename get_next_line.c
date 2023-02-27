/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:10:30 by dajimene          #+#    #+#             */
/*   Updated: 2023/02/27 18:22:42 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	i += (stash[i] == '\n');
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!new_stash)
		return (NULL);
	j = 0;
	while (stash[i + j])
	{
		new_stash[j] = stash[i + j];
		j++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

void	*create_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

//SI LO LEIDO ES MENOR QUE EL BUFFER_SIZE, SIGNIFICA QUE YA NO HAY MAS NADA QUE LEER.

char	*get_next_line(int fd)
{
	static char		*stash[4096];
	char			*buff;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readed = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(stash[fd], '\n') && readed != 0)
	{
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((!stash[fd] && readed == 0) || readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buff);
	}
	free(buff);
	buff = create_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (buff);
}
