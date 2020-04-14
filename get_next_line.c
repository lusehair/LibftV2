/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:39:01 by lusehair          #+#    #+#             */
/*   Updated: 2020/04/14 14:14:44 by lucasseha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int						read_and_match(int fd, char **big, int re)
{
	char				*tmp;
	char				*ttmp;

	if (!(tmp = (char *)malloc(sizeof(char*) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!*big)
		*big = gft_strjoin("", "");
	while (((re = read(fd, tmp, BUFFER_SIZE))))
	{
		if (re < 0)
			return (-1);
		tmp[re] = '\0';
		if (*big)
		{
			ttmp = *big;
			*big = gft_strjoin(*big, tmp);
			free(ttmp);
		}
		if (gft_strchr(*big, '\n'))
			break ;
	}
	free(tmp);
	return (re);
}

int						get_next_line(int fd, char **line)
{
	static char			*big = NULL;
	int					re;
	char				*ttmp;

	if (fd < 0)
		return (-1);
	re = 0;
	if ((re = read_and_match(fd, &big, re)) == -1)
		return (-1);
	if (!gft_strchr(big, '\n'))
	{
		*line = big;
		big = NULL;
		return (0);
	}
	re = 0;
	while (big[re] != '\n')
		re++;
	*line = gft_substr(big, 0, re);
	ttmp = big;
	big = gft_substr(big, re + 1, (int)gft_strlen(big) - (re + 1));
	free(ttmp);
	return (1);
}
