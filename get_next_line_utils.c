/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:13:19 by dajimene          #+#    #+#             */
/*   Updated: 2023/03/07 18:28:59 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *dest, char * stash, char *buff)
{
	int	i;
	int	j;
	int newlen;

	i = 0;
	j = 0;
	newlen = ft_strlen(stash) + ft_strlen(buff);
	while (i <= newlen && stash[i])
	{
		dest[i] = stash[i];
		i++;
	}
	while (i <= newlen && buff[j])
		dest[i++] = buff[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*result;

	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		stash[0] = '\0';
	}
	if (!stash || !buff)
		return (NULL);
	result = (char *)malloc(1 + ft_strlen(stash) + ft_strlen(buff) * sizeof(char));
	if (!result)
		return (NULL);
	result = join(result, stash, buff);
	free(stash);
	return (result);
}

char	*ft_strdup( char *s)
{
	char	*copy;
	char	*src;
	int		i;

	i = 0;
	src = (char *)s;
	if (!src)
		return (NULL);
	copy = (char *)malloc(ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *stash, int c)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == (char)c)
			return ((char *)&stash[i]);
		i++;
	}
	if (stash[i] == (char)c)
		return ((char *)&stash[i]);
	return (NULL);
}