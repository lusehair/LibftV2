/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:20 by lusehair          #+#    #+#             */
/*   Updated: 2020/04/14 14:39:21 by lucasseha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		gft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void		ft_bzero(void *s, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = '\0';
}

char		*gft_strchr(const char *str, int c)
{
	while (str && *str && *str != c)
		str++;
	return (str && *str == c ? (char *)str : NULL);
}

char		*gft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;

	if (!str)
		return (NULL);
	if (start >= gft_strlen(str))
		len = 0;
	i = 0;
	if ((r = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ft_bzero(r, len + 1);
	while (str[i] && i < len)
	{
		r[i] = str[i + start];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char		*gft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*dst;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (!s1 ? s2 : s1);
	size = gft_strlen(s1) + gft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (*s1 != '\0')
		dst[i++] = *s1++;
	while (*s2 != '\0')
		dst[i++] = *s2++;
	dst[i] = '\0';
	return (dst);
}
