/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:38:20 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/08 22:08:45 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name()
{
	DIR	*dir;
	struct dirent *sd;

	dir = opendir(".");
	if(dir == NULL)
	{
		ft_putstr("Error");
		exit(1);
	}
	while((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.' && sd->d_name[ft_strlen(sd->d_name)-1] != '~') 
		{
			ft_putstr(sd->d_name);
			ft_putchar('\n');

		}
	}
	closedir (dir);
}

void	print_time(struct timespec ts)
{
	time_t	curr_time;
	char	*f_ctime;
	char	*f_mtime;

	time(&curr_time);
	f_ctime = ctime(&curr_time);
	f_mtime = ctime(&ts.tv_sec);

	ft_putnstr(&f_mtime[4], 7);

	if (curr_time - ts.tv_sec  > 15780000)
		ft_putnstr(&f_mtime[19], 5);
	else
		ft_putnstr(&f_mtime[11], 5);
}
