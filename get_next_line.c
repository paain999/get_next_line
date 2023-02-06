/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:50:49 by dajimene          #+#    #+#             */
/*   Updated: 2023/02/06 18:46:48 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void cleanner(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		j;
	int		i;

	clean_node = malloc(sizeof(t_list));
	if(*stash == NULL || !clean_node)
		return ;
	last = get_last_node(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ft_strlen(last->content) - i) + 1);
	if(clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	freestash(*stash);
	*stash = clean_node;
}

static void	extract_line(char **line, t_list *stash, int breaker)
{
	int	i;
	int	j;
	
	if(stash == NULL)
		return ;
	create_line(line, stash);
	if(*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		breaker = 1;
		while (stash->content[i] && breaker)
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				breaker = 0;
			}
			else
				(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

static void	add_to_stash(char *buff, t_list **stash, int readed)
{
	int	i;
	t_list	*new_node;
	t_list	*last;
	
	new_node = malloc(sizeof(t_list));
	if(!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char)*(readed+1));
	while (buff[i])
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = get_last_node(*stash);
	last->next = new_node;
}

static void	read_and_stash(int fd, t_list **stash)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (!found_newline(*stash) && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(!buff)
			return ;
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buff);
			return ;
		}
		buff[readed] = '\0';
		add_to_stash(buff, stash, readed);
		free(buff);
	}
}

char	*get_next_line(int fd)
{
	static	t_list	*stash;
	char			*line;
	int	breaker;
	
	breaker = 1;
	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = NULL;
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);	
	extract_line(&line, stash, breaker);
	cleanner(&stash);
	if (line[0] == '\0')
	{
		freestash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}