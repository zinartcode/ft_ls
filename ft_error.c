/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 23:43:54 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/10 23:47:25 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lserror(char *str)
{
	int	i;

	i = 0;
	write(2, "ft_ls: ", 7);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, ": ", 2);
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}