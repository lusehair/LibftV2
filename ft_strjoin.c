/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:12:54 by lusehair          #+#    #+#             */
/*   Updated: 2019/11/08 12:31:11 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	is;
	size_t	id;

	is = 0;
	id = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_calloc((ft_strlen(s1) + ft_strlen(s2)), sizeof(char))))
		return (NULL);
	while (s1[is] != '\0')
	{
		str[id] = s1[is];
		id++;
		is++;
	}
	is = 0;
	while (s2[is] != '\0')
	{
		str[id] = s2[is];
		id++;
		is++;
	}
	str[id] = '\0';
	return (str);
}
