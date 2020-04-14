/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:44:46 by lusehair          #+#    #+#             */
/*   Updated: 2019/11/08 12:29:26 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *str;
	unsigned char		letter;
	size_t				i;

	str = s;
	letter = c;
	i = 0;
	while (n--)
	{
		if (str[i] == letter)
			return (void*)(&s[i]);
		i++;
	}
	return (NULL);
}
