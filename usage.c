/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:51:45 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/09 15:28:48 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int usage(void)
{

	DIR	*dir;
	struct	dirent *sd;
	struct	stat mystat;

	// struct 	passwd *grd;	
	// char buf[512];

	// pwd = getpwuid(mystat.st_uid);
	// grd = getpwnam(mystat.st_gid);
	dir = opendir(".");
	if(dir == NULL)
	{
		ft_putstr("Error");
		exit(1);
	}
	total_size();
	while((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.' && sd->d_name[ft_strlen(sd->d_name)-1] != '~') 
		{
			if ((stat(sd->d_name, &mystat)) == 0)
			{
				print_filetype(mystat.st_mode);
				print_permissions(mystat.st_mode);
				ft_putchar(' ');
				ft_putnbr(mystat.st_nlink);
				ft_putchar(' ');
				print_user_group(mystat);
				ft_putchar(' ');
				ft_putchar(' ');
				ft_putnbr(mystat.st_size);
				ft_putchar(' ');				
				print_time(mystat.st_mtimespec);
				ft_putchar(' ');
				ft_putstr(sd->d_name);
				ft_putchar('\n');

			}
			else
			{	
				ft_putstr("Error");
				exit(1);
			}
		}
	}


	closedir (dir);

    return 0;
}