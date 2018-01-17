/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:54:45 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/16 00:56:14 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				process_args(t_opt *opts, DIR *dir)
{
	struct stat		mystat;
	struct dirent	*sd;
	char			*p;
	t_file			*list;

	list = ft_memalloc(sizeof(t_file));
	clear_file(list);
	while ((sd = readdir(dir)) != NULL)
	{
		if (opts->is_a == 0 && sd->d_name[0] == '.')
		{
			p = NULL;
			continue;
		}
		else
			p = ft_new_path(opts->path, sd->d_name);
		if ((lstat(p, &mystat)) == 0)
		{
			list->total += mystat.st_blocks;
			list->nfiles++;
		}
	}
	process_args2(opts, list, dir);
	free(list);
}

void				process_args2(t_opt *opts, t_file *list, DIR *dir)
{
	t_file			**file;
	int				i;

	i = 0;
	list->isdir = 1;
	dir = opendir(opts->path);
	file = ft_memalloc(list->nfiles * sizeof(file));
	process_args3(opts, file, dir, i);
	closedir(dir);
	sort_files(opts, list, file);
	display_files(opts, list, file);
	free(file);
}

void				process_args3(t_opt *opts, t_file **file, DIR *dir, int i)
{
	char			*p;
	struct stat		mystat;
	struct dirent	*sd;

	while ((sd = readdir(dir)) != NULL)
	{
		file[i] = ft_memalloc(sizeof(t_file));
		if (opts->is_a == 0 && sd->d_name[0] == '.')
		{
			p = opts->path;
			continue;
		}
		else
			p = ft_new_path(opts->path, sd->d_name);
		if ((lstat(p, &mystat)) == 0)
		{
			file[i]->name = ft_strdup(sd->d_name);
			file[i]->path = ft_strdup(p);
			getstats(&mystat, file[i]);
		}
		free(p);
		i++;
	}
}

void				check_arg(t_opt *opts, char *av)
{
	DIR				*dir;
	struct stat		myst;
	int				n;

	opts->path = av;
	n = stat(opts->path, &myst);
	dir = ft_memalloc(sizeof(DIR));
	if (((dir = (DIR*)opendir(opts->path)) != NULL) && S_ISDIR(myst.st_mode))
	{
		process_args(opts, dir);
		closedir(dir);
	}
	else if (((dir = (DIR*)opendir(opts->hp)) != NULL) && S_ISREG(myst.st_mode))
		closedir(dir);
	else
	{
		ft_lserror(av);
		ft_puterror(strerror(errno));
		write(2, "\n", 1);
	}
}

void				process_flags(char *av, t_opt *opts)
{
	if (av[0] == '-' && av[1] != '\0' && opts->argf == 0)
	{
		get_flags(opts, &av);
		opts->flag++;
	}
	else
		opts->argf++;
}
