/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:50:52 by dajimene          #+#    #+#             */
/*   Updated: 2023/02/03 15:03:32 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	freestash(t_list *stash)
{
	t_list *current;
	t_list *next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;
	
	if (stash == NULL)
		return (0);
	current = get_last_node(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);	
}

t_list	*get_last_node(t_list *stash)
{
	t_list *current;
	
	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	create_line(char **line, t_list *stash)
{
	int	i;
	int	len;
	int	breaker;
	
	len = 0;
	while (stash)
	{
		breaker = 1;
		i = 0;
		while (stash->content[i] && breaker)
		{
			if (stash->content[i] == '\n')
			{
				len++;
				breaker = 0;
			}
			else
			{
				len++;
				i++;
			}
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}