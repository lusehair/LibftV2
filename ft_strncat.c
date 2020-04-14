/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:12:28 by lusehair          #+#    #+#             */
/*   Updated: 2019/10/18 11:34:47 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t id;
	size_t is;

	id = 0;
	is = 0;
	while (s1[id])
	{
		id++;
	}
	while ((is < n) && s2[is])
	{
		s1[id] = s2[is];
		is++;
		id++;
	}
	s1[id] = '\0';
	return (s1);
}
