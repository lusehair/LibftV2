/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <lusehair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:32:45 by lusehair          #+#    #+#             */
/*   Updated: 2019/11/08 14:41:57 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbsplit(const char *s, char c)
{
	int	i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			nb++;
		}
	}
	return (nb);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if ((str = (char**)malloc(sizeof(char*) * (nbsplit(s, c) + 1))) == NULL)
		return (NULL);
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && (s[end] != c))
			end++;
		if (s[end] == c || (s[end] == '\0' && s[end - 1] != c))
			str[i++] = ft_substr(s, start, (end - start));
	}
	str[i] = NULL;
	return (str);
}
