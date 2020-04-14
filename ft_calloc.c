/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:40:23 by lusehair          #+#    #+#             */
/*   Updated: 2019/11/08 12:26:27 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char *ptr;

	if (!(ptr = malloc(size * count)))
		return (NULL);
	count *= size;
	while (count--)
		ptr[count] = 0;
	return (ptr);
}
