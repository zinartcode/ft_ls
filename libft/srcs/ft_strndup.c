/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 04:17:39 by ydang             #+#    #+#             */
/*   Updated: 2016/10/29 04:17:41 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char *dst;

	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	dst = ft_strncpy(dst, s1, n);
	dst[n] = '\0';
	return (dst);
}
