/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:46:29 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/07 18:20:04 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int main(void)
{

	DIR	*dir;
	struct dirent *sd;
	struct stat mystat;
	// char buf[512];

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
			if ((stat(sd->d_name, &mystat)) == 0)
			{
				print_permissions(mystat.st_mode);
				ft_putnbr(mystat.st_nlink);
				ft_putchar(' ');
				ft_putnbr(mystat.st_size);
				ft_putchar(' ');
				ft_putstr(ctime(&mystat.st_mtime));
				// ft_putchar(' ');
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
