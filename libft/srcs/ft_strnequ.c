/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:38:00 by ydang             #+#    #+#             */
/*   Updated: 2016/10/12 13:38:02 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 == NULL && s2 != NULL)
		return (0);
	if (s2 == NULL && s1 != NULL)
		return (0);
	if (s1 == NULL && s2 == NULL)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && n > 0)
	{
		if (s1[i] != s2[i])
			return (0);
		if (n == 1)
			return (1);
		i++;
		n--;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
