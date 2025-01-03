/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:39:32 by bhajili           #+#    #+#             */
/*   Updated: 2024/09/24 23:45:55 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, t_cchr *src)
{
	return (ft_strncat(dest, src, ft_strlen(src)));
}

char	*ft_strncat(char *dest, t_cchr *src, size_t n)
{
	return (ft_strncpy(dest + ft_strlen(dest), src, n + 1));
}

char	*ft_strcpy(char *dest, t_cchr *src)
{
	return (ft_strncpy(dest, src, ft_strlen(src) + 1));
}

char	*ft_strncpy(char *dest, t_cchr *src, t_unint n)
{
	t_unint	i;

	i = -1;
	if (!dest || !src)
		return (NULL);
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
