/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajimene <dajimene@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:13:13 by dajimene          #+#    #+#             */
/*   Updated: 2023/03/06 19:50:06 by dajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>


char	*get_next_line(int fd);
char	*ft_strjoin(char *stash, char *buff);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_strchr(char *str, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif