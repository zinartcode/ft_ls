/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:38:20 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/26 23:57:41 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file(t_opt *opts)
{
	ft_putstr(opts->path);
	ft_putchar('\n');
}

// void	print_name()
// {
// 	DIR	*dir;
// 	struct dirent *sd;

// 	dir = opendir(".");
// 	if(dir == NULL)
// 	{
// 		ft_putstr("Error");
// 		exit(1);
// 	}
// 	while((sd = readdir(dir)) != NULL)
// 	{
// 		if (sd->d_name[0] != '.' && sd->d_name[ft_strlen(sd->d_name)-1] != '~') 
// 		{
// 			ft_putstr(sd->d_name);
// 			ft_putchar('\n');

// 		}
// 	}
// 	closedir (dir);
// }


void	print_time(time_t *date)
{
	time_t	curr_time;
	char	*f_ctime;
	char	*f_mtime;

	curr_time = time(NULL);
	f_ctime = ctime(&curr_time);
	f_mtime = ctime(date);

	ft_putnstr(&f_mtime[4], 7);

	if (curr_time - *date  > 15780000)
		ft_putnstr(&f_mtime[19], 5);
	else
		ft_putnstr(&f_mtime[11], 5);
}
// int	mod_time(int mt)
// {
// 	time_t curr_time;
// 	char	*f_mtime;
// 	char	*mod_time;

// 	time(&curr_time);
// 	f_mtime = ctime(&f_mtime.tv_sec);
// 	if (curr_time - mt  > 15780000)
// 		mod_time = f_mtime[19], 5
// }

void	print_user_group(struct stat mystat)
{
	struct	passwd *pwd;  //for used-ID	
	struct	group *grp;   //for group-ID

	pwd = getpwuid(mystat.st_uid);
	grp = getgrgid(mystat.st_gid);
	ft_putstr(pwd->pw_name);
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putstr(grp->gr_name);

}

void	total_size(void)
{
	DIR *dir;
	struct	dirent *sd;
	struct	stat mystat;
	int	total;

	total = 0;
	dir = opendir(".");
	if(dir == NULL)
	{
		ft_putstr("Error");
		exit(1);
	}
	while((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.' && sd->d_name[ft_strlen(sd->d_name)-1] != '~') //create func is_hidden(0:1)
		{
			if ((stat(sd->d_name, &mystat)) == 0)
			{
				total += mystat.st_blocks;
			}
		}
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
}
