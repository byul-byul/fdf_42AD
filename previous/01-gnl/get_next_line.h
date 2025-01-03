/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:38 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/18 13:51:55 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef MAX_FD
#  define MAX_FD 1
# endif

# define SEPARATOR '\n'

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);

#endif