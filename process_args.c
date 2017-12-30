/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:54:45 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/29 22:36:13 by azinnatu         ###   ########.fr       */
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

void	process_args(t_opt *opts, t_file *list, DIR *dir)
{
	struct stat mystat;
	struct dirent *sd;
	char	*p;

	list->nfiles = 0;
	list->total = 0;
	dir  = opendir(opts->path);
	while ((sd = readdir(dir)) != NULL)
	{
		if (opts->is_a == 0 && sd->d_name[0] == '.')
		{
			p = opts->path;
			break;
		}
		else
		p = ft_new_path(opts->path, sd->d_name);
		if ((stat(p, &mystat)) == 0)
			list->total += mystat.st_blocks;
			list->nfiles++;
	}
		closedir(dir);
		// test_opts(opts);
		// free(p);
		process_args2(opts, list, dir);
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
		p = ft_new_path(opts->path, sd->d_name);
		if ((stat(p, &mystat)) == 0)
		{
			getstats(&mystat, file[i]);
			file[i]->name = sd->d_name;
		}
		i++;
		// free(p);
	}
	closedir(dir);
	sort_files(opts, list, file);
	// while (i != 0)
	// {
	// 	free(file[i]);
	// 	i--;
	// }
	// free(file);
	// free(list);
}

void check_arg(t_opt *opts, char **av)
{
	DIR	*dir;
	struct stat mystat;
	t_file *list;

	list = ft_memalloc(sizeof(t_file));
	if (av[0][0] != '-')
	{
		// if (strcmp(opts->path, ".") != 0)
		opts->path = *av;
	// else
		// printf("my dir is: %s\n", opts->path);
		dir = opendir(opts->path);
		if (stat(opts->path, &mystat) == 0 && S_ISDIR(mystat.st_mode))
			process_args(opts, list, dir);
		else if (stat(opts->path, &mystat) == 0 && S_ISREG(mystat.st_mode))
		{
			print_file(opts);
			exit(0);
		}
		else
		{
			ft_putstr("ft_ls: ");  
			ft_putstr(*av);  
			ft_putstr(": No such file or directory\n");
			exit(1);
		}
		closedir(dir);
	}
}

void	check_file(char *n)
{
	n = NULL;
}

char	*ft_new_path(char *original, char *name)
{
	int		len;
	char	*temp;

	len = ft_strlen(original);
	if ((*original) && ((original)[len - 1] != '/'))
		original = ft_strjoin(original, "/");
		temp = ft_strjoin(original, name);
		free(original);
		return(temp);
}