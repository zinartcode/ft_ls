/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:27:45 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/17 22:30:51 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_files(t_opt *opts, t_file *list, t_file **file)
{
	int	i;

	i = 0;
	if (opts->is_l == 0)
	{
		if (opts->is_upper_r == 1)
			print_total(opts, list);
		while (i < list->nfiles)
		{
			print_total(opts, list);
			ft_putstr(file[i]->name);
			ft_putchar('\n');
			i++;
		}
	}
	if (opts->is_l == 1)
		process_l(opts, list, file);
	if (opts->is_upper_r == 1)
	{
		opts->i = 2;
		process_upper_r(opts, list, file);
	}
}

void	find_files(char **av, t_opt *opts, int i)
{
	int		n;
	int		j;

	opts->flag = 1;
	while (av[i] != '\0')
	{
		process_flags(av[i], opts);
		i++;
	}
	n = opts->argf;
	opts->argf = 0;
	j = opts->flag;
	opts->flag = 0;
	if (n == 0)
	{
		check_arg(opts, opts->hp);
		exit(0);
	}
	else
		ft_files(av, opts, n, j);
}

void	ft_files(char **av, t_opt *opts, int n, int j)
{
	t_file	**file;
	t_file	*list;
	int		k;

	k = 0;
	list = ft_memalloc(sizeof(t_file));
	file = ft_memalloc(n * sizeof(file));
	file[k] = ft_memalloc(sizeof(t_file));
	clear_file(list);
	while (n > 0)
	{
		clear_file(file[k]);
		ft_file(opts, av[j], list, file[k]);
		j++;
		if (list->nfiles > k)
		{
			k++;
			file[k] = ft_memalloc(sizeof(t_file));
		}
		n--;
	}
	sort_files(opts, list, file);
	display_files(opts, list, file);
	free(file);
	free(list);
}

void	ft_file(t_opt *opts, char *av, t_file *list, t_file *file)
{
	DIR				*dir;
	struct stat		myst;
	char			*p;

	dir = ft_memalloc(sizeof(DIR));
	if (ft_strcmp(opts->hp, av) == 0)
		p = ft_strdup(av);
	else
		p = ft_new_path(opts->hp, av);
	if (stat(p, &myst) == 0 && S_ISREG(myst.st_mode))
	{
		opts->argf++;
		dir = opendir(opts->hp);
		file->name = ft_strdup(av);
		file->path = ft_strdup(p);
		getstats(&myst, file);
		closedir(dir);
		list->nfiles++;
	}
	else if (stat(p, &myst) == 0 && S_ISDIR(myst.st_mode))
		opts->i++;
	else
		check_arg(opts, av);
	free(p);
}

void	clear_file(t_file *file)
{
	file->isdir = 0;
	file->nfiles = 0;
	file->path = NULL;
	ft_memset(file->permissions, 0, 11);
	file->nlinks = 0;
	file->username = NULL;
	file->groupname = NULL;
	file->byte_size = 0;
	file->block_size = 0;
	file->date_raw = 0;
	file->total = 0;
	file->sub_dirs = NULL;
	file->name = NULL;
	file->date = 0;
}
