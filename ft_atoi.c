/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusehair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:58:09 by lusehair          #+#    #+#             */
/*   Updated: 2019/10/16 13:43:28 by lusehair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int num;
	int neg;

	i = 0;
	num = 0;
	neg = 1;
	if (ft_strlen(str) == 0)
		return (0);
	while (((str[i] >= 8) && (str[i] <= 13)) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (((str[i] >= '0') && (str[i] <= '9')))
	{
		num *= 10;
		num += (str[i] - 48);
		i++;
	}
	return (num * neg);
}
