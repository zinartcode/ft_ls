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

void	get_flags(t_opt *opts, char **av)
{
	size_t			i;

	i = ft_strlen(*av);
	if (av[0][0] == '-' && av[0][1] != '\0')
	{
		while (--i >= 1)
		{
		if (av[0][i] == 'l')
			opts->is_l = 1;
		else if (av[0][i] == 'R')
			opts->is_upper_r = 1;
		else if (av[0][i] == 'a')
			opts->is_a = 1;
		else if (av[0][i] == 'r')
			opts->is_lower_r = 1;
		else if (av[0][i] == 't')
			opts->is_t = 1;
		else
			{
				ft_putstr("ft_ls: illegal option -- ");
				ft_putchar(av[0][i]);
				ft_putstr("\nusage: ft_ls [-ABCFGHLOPRSTUW");
				ft_putstr("abcdefghiklmnopqrstuwx1] [file ...]\n");
				exit(1);
			}
		}
	}
}

void	process_args(t_opt *opts, DIR *dir)
{
	struct stat mystat;
	struct dirent *sd;
	char	*p;
	t_file *list;

	list = ft_memalloc(sizeof(t_file));
	clear_file(list);
	dir  = opendir(opts->path);
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
		free(p);
	}
		closedir(dir);
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
			file[i]->name = sd->d_name;
			file[i]->path = p;
			getstats(&mystat, file[i]);
		}
		free(p);
		i++;
	}
	closedir(dir);
	sort_files(opts, list, file);
}

void check_arg(t_opt *opts, char *av)
{
	DIR	*dir;
	struct stat mystat;

	if (av[0] != '-')
	{
		opts->path = av;
		dir = opendir(opts->path);
		if (stat(opts->path, &mystat) == 0 && S_ISDIR(mystat.st_mode))
			process_args(opts, dir);
		else if (stat(opts->path, &mystat) == 0 && S_ISREG(mystat.st_mode))
		{
			print_file(opts);
			exit(0);
		}
		else
		{
			ft_putstr("ft_ls: ");  
			ft_putstr(av);  
			ft_putstr(": No such file or directory\n");
			exit(1);
		}
		closedir(dir);
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