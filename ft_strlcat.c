/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:11:03 by lusehair          #+#    #+#             */
/*   Updated: 2019/10/17 17:12:23 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t destlen;
	size_t srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destsize == 0)
		return (srclen);
	if (destlen < destsize)
	{
		ft_strncat(dest, src, (destsize - destlen - 1));
		return (destlen + srclen);
	}
	else
		return (destsize + srclen);
}
