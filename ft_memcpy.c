/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:57:39 by lusehair          #+#    #+#             */
/*   Updated: 2019/11/08 12:29:44 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while ((i < n))
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}
