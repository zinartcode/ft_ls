/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 00:21:58 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/16 00:58:13 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	find_dirs(char **av, t_opt *opts, int i)
{
	t_file	**dfile;
	t_file	*dlist;
	int		n;

	n = 0;
	dlist = ft_memalloc(sizeof(t_file));
	dfile = ft_memalloc(opts->i * sizeof(dfile));
	dfile[n] = ft_memalloc(sizeof(t_file));
	clear_file(dlist);
	while (av[i] != '\0')
	{
		if ((av[i][0] != '-') || (av[i][0] == '.' && av[i][1] == '\0'))
		{
			clear_file(dfile[n]);
			ft_dir(opts, av[i], dlist, dfile[n]);
			if (dfile[n]->isdir == 1)
			{
				n++;
				dfile[n] = ft_memalloc(sizeof(t_file));
			}
		}
		i++;
	}
	run_dir(opts, dlist, dfile, n);
	free(dlist);
}

void	run_dir(t_opt *opts, t_file *list, t_file **file, int n)
{
	int	m;

	m = 0;
	sort_files(opts, list, file);
	while (m < n)
	{
		if (opts->i != 0)
			opts->subdir = 1;
		opts->argd = m;
		check_arg(opts, file[m]->path);
		free(file[m]);
		m++;
	}
	free(file);
}

void	ft_dir(t_opt *opts, char *av, t_file *list, t_file *file)
{
	DIR				*dir;
	struct stat		myst;
	char			*p;

	dir = ft_memalloc(sizeof(DIR));
	p = ft_new_path(opts->hp, av);
	if (ft_strcmp(opts->hp, av) == 0)
		p = ft_strdup(av);
	if (stat(p, &myst) == 0 && S_ISDIR(myst.st_mode))
	{
		dir = opendir(opts->hp);
		file->name = ft_strdup(av);
		file->path = ft_strdup(p);
		getstats(&myst, file);
		closedir(dir);
		free(p);
		list->isdir++;
		list->nfiles++;
	}
}

int		ok_to_recurse(char *path)
{
	if (ft_strcmp(path, ".") == 0)
		return (0);
	if (ft_strcmp(path, "..") == 0)
		return (0);
	return (1);
}
