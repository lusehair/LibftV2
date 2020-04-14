/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:47:18 by lusehair          #+#    #+#             */
/*   Updated: 2019/10/08 17:01:32 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
#define FT_LIBFT_H

int		ft_atoi(char *str); 
int		ft_isalum(int c); 
int		ft_isalpha(int c); 
int		ft_isascii(int c); 
int		ft_isdigit(int c); 
int		ft_isprint(int c); 
char	*ft_strchr(const char *str, int c); 
char	*ft_strrchr(const char *str, int c); 
int		ft_strlen(char *str); 
int		ft_tolower(int	c); 
int		ft_toupper(int c); 
int		ft_strncmp(const char*s1, const char *s2, size_t n); 
#endif
