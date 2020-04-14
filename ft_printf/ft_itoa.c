/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucassehairi <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 12:46:51 by lucasseha         #+#    #+#             */
/*   Updated: 2020/03/06 19:35:19 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				sizenb(int n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	int				i;
	char			*str;
	int				nb;

	nb = n;
	i = 0;
	str = (char *)malloc(sizeof(char) * (sizenb(n) + 1));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		nb = n * -1;
	while (nb > 0)
	{
		str[i++] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

static int			ft_get_nb_size(unsigned int nb)
{
	long			size;

	size = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

static char			*ft_convert_int_to_char(char *str, unsigned int size,
unsigned int nb)
{
	str[size--] = '\0';
	while (nb > 0)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}

char				*ft_uitoa(unsigned int n)
{
	unsigned int	size;
	char			*str;

	str = 0;
	size = ft_get_nb_size(n);
	if (n == 0)
		size = 2;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	if (n == 0)
	{
		str[1] = '\0';
		str[0] = '0';
	}
	else
	{
		size--;
		ft_convert_int_to_char(str, size, n);
	}
	return (str);
}
