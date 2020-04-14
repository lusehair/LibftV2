/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:18:08 by lusehair          #+#    #+#             */
/*   Updated: 2019/10/15 16:34:00 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	size_t			i;
	unsigned char	l;
	unsigned char	*mystr;

	mystr = str;
	l = c;
	i = 0;
	while (i < size)
	{
		mystr[i] = l;
		i++;
	}
	return (str);
}
