/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:37:23 by lusehair          #+#    #+#             */
/*   Updated: 2019/11/06 12:14:06 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	fi;

	i = 0;
	fi = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + fi] && (haystack[i + fi] == needle[fi]) && i +
				fi < len)
		{
			fi++;
			if (fi == ft_strlen(needle))
				return ((char*)haystack + i);
		}
		fi = 0;
		i++;
	}
	return (NULL);
}
