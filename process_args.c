/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:54:45 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/29 23:25:50 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_args(t_opt *opts, DIR *dir)
{
	struct stat mystat;
	struct dirent *sd;
	char	*p;
	t_file *list;

	list = ft_memalloc(sizeof(t_file));
	clear_file(list);
	while ((sd = readdir(dir)) != NULL)
	{
		if(opts->is_a == 0 && sd->d_name[0] == '.')
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

void	process_args2(t_opt *opts, t_file *list, DIR *dir)
{
	struct stat mystat;
	struct dirent *sd;
	char	*p;
	t_file **file;
	int	i;

	i = 0;
	dir  = opendir(opts->path);
	file = ft_memalloc(list->nfiles * sizeof(file));
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
	closedir(dir);
	sort_files(opts, list, file);
}

// void	process_args2(t_opt *opts, t_file *list, DIR *dir, char *p)
// {
// 	struct stat mystat;
// 	struct dirent *sd;
// 	t_file **file;
// 	int	i;

// 	i = 0;
// 	dir  = opendir(opts->path);
// 	file = ft_memalloc(list->nfiles * sizeof(file));
// 	while ((sd = readdir(dir)) != NULL)
// 	{
// 		file[i] = ft_memalloc(sizeof(t_file));
// 		if (opts->is_a != 0 && sd->d_name[0] != '.')
// 		p = ft_new_path(opts->path, sd->d_name);
// 		if ((lstat(p, &mystat)) == 0)
// 		{
// 			file[i]->name = sd->d_name;
// 			file[i]->path = ft_strdup(p);
// 			getstats(&mystat, file[i]);
// 		}
// 		i++;
// 	}
// 	free(p);
// 	closedir(dir);
// 	sort_files(opts, list, file);
// }

void check_arg(t_opt *opts, char *av)
{
	DIR	*dir;
	struct stat mystat;

	if (av[0] != '-')
	{
		opts->path = av;
		if (stat(opts->path, &mystat) == 0 && S_ISDIR(mystat.st_mode))
		{
			dir = opendir(opts->path);
			process_args(opts, dir);
			closedir(dir);
		}
		else if (stat(opts->path, &mystat) == 0 && S_ISREG(mystat.st_mode))
		{
			ft_putstr(opts->path);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr("ft_ls: ");
			ft_putstr(av);  
			ft_putstr(": No such file or directory\n");
			exit(1);
		}
	}
}


char	*ft_new_path(char *original, char *name)
{
	int		len;
	char	*temp;
	char 	*t;

	len = ft_strlen(original);
	if ((*original) && ((original)[len - 1] != '/'))
	{
		t = ft_strjoin(original, "/");
		temp = ft_strjoin(t, name);
		free(t);
		return(temp);
	}
	
		return(ft_strjoin(original, name));
}