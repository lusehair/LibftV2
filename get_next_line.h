/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:31:16 by lusehair          #+#    #+#             */
/*   Updated: 2020/04/14 14:13:31 by lucasseha        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

size_t				gft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
char				*gft_strchr(const char *s, int c);
char				*gft_substr(char const *s, unsigned int start, size_t len);
char				*gft_strjoin(char *s1, char *s2);
int					get_next_line(int fd, char **line);

#endif
