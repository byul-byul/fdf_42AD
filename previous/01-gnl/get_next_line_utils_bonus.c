/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:58 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/18 13:47:18 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
		while (*s != (char)c)
			if (!*s++)
				return (NULL);
	return ((char *)s);
}

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	if (!dest || !src)
		return (NULL);
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	sublen;

	if (!str)
		return (NULL);
	sublen = ft_strlen(str);
	if (sublen <= start)
		sublen = 0;
	else
		sublen -= start;
	if (sublen > len)
		sublen = len;
	res = (char *)malloc(sizeof(char) * (sublen + 1));
	if (res)
	{
		ft_strncpy(res, str + start, sublen);
		res[sublen] = '\0';
	}
	return (res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < s1_len)
		res[i++] = s1[j++];
	j = 0;
	while (j < s2_len)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
