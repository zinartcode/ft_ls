/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:51:45 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/08 21:28:01 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_type(struct stat *mystat, t_file *list)
{
	if (S_ISREG(mystat->st_mode))
		list->permissions[0] = '-';
	else if (S_ISLNK(mystat->st_mode))
		list->permissions[0] = 'l';
	else if (S_ISDIR(mystat->st_mode))
	{
		list->isdir = 1;
		list->permissions[0] = 'd';
	}
	else if (S_ISCHR(mystat->st_mode))
		list->permissions[0] = 'c';
	else if (S_ISBLK(mystat->st_mode))
		list->permissions[0] = 'b';
	else if (S_ISFIFO(mystat->st_mode))
		list->permissions[0] = 'p';
	else if (S_ISSOCK(mystat->st_mode))
		list->permissions[0] = 's';
	else
		list->permissions[0] = '?';
}

void	getstats(struct stat *mystat, t_file *list)
{
	get_type(mystat, list);
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

void	process_l(t_opt *opts, t_file *list, t_file **file)
{
	int	i;

	i = 0;
	if (opts->is_l == 1 || opts->subdir == 1)
	{
		print_total(opts, list);
		while (i < list->nfiles)
		{
			print_l(file[i]);
			i++;
		}
	}
}

void	process_upper_r(t_opt *opts, t_file *list, t_file **file)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)ft_memalloc(sizeof(char) * (ft_strlen(opts->path) + 1));
	while (i < list->nfiles)
	{
		if ((file[i]->isdir == 1) && (ok_to_recurse(file[i]->name) != 0))
		{
			p = ft_strdup(opts->path);
			opts->path = ft_new_path(opts->path, file[i]->name);
			opts->subdir = 1;
			opts->argd = 1;
			check_arg(opts, file[i]->path);
			opts->path = file[i]->path;
		}
		free(file[i]);
		i++;
	}
	free(p);
}

int		ok_to_recurse(char *path)
{
	if (ft_strcmp(path, ".") == 0)
		return (0);
	if (ft_strcmp(path, "..") == 0)
		return (0);
	return (1);
}
