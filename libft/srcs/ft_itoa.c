/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:46:33 by azinnatu          #+#    #+#             */
/*   Updated: 2017/07/26 15:46:35 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ch_sign(int n)
{
	if (n > 0)
		return ('+');
	else if (n < 0)
		return ('-');
	return ('0');
}

char		*ft_itoa(int n)
{
	char			sign;
	char			*str;
	short			index;
	unsigned int	tmp;
	unsigned int	v;

	sign = ch_sign(n);
	v = sign == '-' ? -n : n;
	tmp = v;
	index = sign != '+' ? 1 : 0;
	while (tmp)
	{
		index++;
		tmp /= 10;
	}
	if (!(str = ft_strnew(index)))
		return (NULL);
	str[0] = sign;
	while (v)
	{
		index--;
		str[index] = v % 10 + '0';
		v /= 10;
	}
	return (str);
}
