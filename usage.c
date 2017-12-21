/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:51:45 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/20 23:13:18 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int usage(char **av)
{
	DIR	*dir;
	struct	dirent *sd;
	struct	stat mystat;
	t_file *list;
	 int	i;

	 i = 0;
	 list = ft_memalloc(sizeof(t_file));
	 ft_putstr("my av: ");
	 ft_putstr(*av);  //av from main.c
	 ft_putchar('\n');

	dir = opendir(".");
	if(dir == NULL)
	{
		ft_putstr("Error");
		exit(1);
	}

	while((sd = readdir(dir)) != NULL)
	{
		if ((stat(sd->d_name, &mystat)) == 0)
		{
			list->total +=mystat.st_blocks;
			i++;
		}
	}
	ft_putstr("total ");
	ft_putnbr(list->total);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');

		dir = opendir(".");
	if(dir == NULL)
	{
		ft_putstr("Error");
		exit(1);
	}
		closedir(dir);

    return 0;
}

void	getstats(struct stat *mystat, t_file *list)

{

			list->permissions[0] = (S_ISDIR(mystat->st_mode)) ? 'd' : '-';
			list->permissions[1] = (mystat->st_mode & S_IRUSR) ? 'r' : '-';
			list->permissions[2] = (mystat->st_mode & S_IWUSR) ? 'w' : '-';
			list->permissions[3] = (mystat->st_mode & S_IXUSR) ? 'x' : '-';
			list->permissions[4] = (mystat->st_mode & S_IRGRP) ? 'r' : '-';
			list->permissions[5] = (mystat->st_mode & S_IWGRP) ? 'w' : '-';
			list->permissions[6] = (mystat->st_mode & S_IXGRP) ? 'x' : '-';
			list->permissions[7] = (mystat->st_mode & S_IROTH) ? 'r' : '-';
			list->permissions[8] = (mystat->st_mode & S_IWOTH) ? 'w' : '-';
			list->permissions[9] = (mystat->st_mode & S_IXOTH) ? 'x' : '-';
			list->permissions[10] = '\0';
			list->nlinks = (int)mystat->st_nlink;
			list->username = getpwuid(mystat->st_uid)->pw_name;
			list->groupname = getgrgid(mystat->st_gid)->gr_name;
			list->byte_size = (int)mystat->st_size;
			list->block_size = (int)mystat->st_blocks;
			list->date_raw = (int)mystat->st_mtimespec.tv_sec;
			// list->name = sd->d_name;
			// printf("my name: %s\n", list->username);  //tes
			print_l(list);
			// ft_putchar('\n');  //test
			// return(*list);

			// ft_putstr(list->name);
			// ft_putchar('\n');
			// list->date = mod_time(mystat->st_mtimespec.tv_sec);
			// list->nfiles = i++;
		// }
		

}
