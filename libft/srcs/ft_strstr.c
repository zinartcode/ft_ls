/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 22:36:58 by ydang             #+#    #+#             */
/*   Updated: 2016/09/26 22:36:59 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	if (*little == '\0')
		return ((char*)big);
	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j])
		{
			if (little[j + 1] == '\0')
			{
				return (char*)(big + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
