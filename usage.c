/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:51:45 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/29 02:14:36 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
}

void	sort_files(t_opt *opts, t_file *list, t_file **file)
{
	int	i;

	i = 0;
	sort_ar(file, list->nfiles);
	if (opts->is_lower_r == 1 && opts->is_t == 0)
		sort_ar_rev(file, list->nfiles);
	if (opts->is_t == 1)
		sort_date(file, list->nfiles);
	if (opts->is_t == 1 && opts->is_lower_r == 1)
		sort_date_rev(file, list->nfiles);
	if (opts->is_l == 0)
	{
		if (opts->is_upper_r == 1)
		print_total(opts, list);
		while (i < list->nfiles)
		{
		print_name(file[i]);
		i++;
		}
		i = 0;
	}
	if (opts->is_l == 1 || opts->is_upper_r == 1)
	process_opts(opts, list, file);
}

void	print_total(t_opt *opts, t_file *list)
{
	if (opts->subdir == 1)
	{
		ft_putchar('\n');
		ft_putstr(opts->path);
		ft_putchar(':');
		ft_putchar('\n');
		opts->subdir = 0;
	}
	if (opts->is_l == 1)
	{
		ft_putstr("total ");
		ft_putnbr(list->total);
		ft_putchar('\n');
	}
}

void	process_opts(t_opt *opts, t_file *list, t_file **file)
{
	int	i;
	DIR *dir;

	i = 0;
	if (opts->is_l == 1)
	{
		print_total(opts, list);
		while (i < list->nfiles)
		{
		print_l(file[i]);
		i++;
		}
	}
	if (opts->is_upper_r == 1)
	{
		i = 0;
		while (i < list->nfiles)
		{
			if (file[i]->permissions[0] == 'd' && file[i]->name[0] != '.')
			{
				opts->path = ft_new_path(opts->path, file[i]->name);
				opts->subdir = 1;
				process_args(opts, *file, dir);
				// printf("this is dir: %s\n", file[i]->name);
			}
			i++;
		}
	}
}

