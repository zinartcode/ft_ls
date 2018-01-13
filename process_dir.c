/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 00:21:58 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/12 01:24:11 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	find_dirs(char **av, t_opt *opts, int i)
{
	t_file	**dfile;
	t_file	*dlist;
	int		n;
	int		m;

	n = 0;
	m = 0;
	dlist = ft_memalloc(sizeof(t_file));
	dfile = ft_memalloc(opts->i * sizeof(dfile));
	dfile[n] = ft_memalloc(sizeof(t_file));
	clear_file(dlist);
	while (av[i] != '\0')
	{
		// printf("av[i] is: %s\n", av[i]);
		if (av[i][0] != '-' && av[i][1] != '\0')
		{

			clear_file(dfile[n]);
			check_if_dir(opts, av[i], dlist, dfile[n]);
			if (dfile[n]->isdir == 1)
			{
				// printf("av[i] is dir: %s\n", av[i]);
				// printf("n is: %d\n", n);
				n++;
				dfile[n] = ft_memalloc(sizeof(t_file));
			}
				// opts->subdir = 1;
		}
		i++;
	}
	sort_files(opts, dlist, dfile);
	// printf("n is: %d   ", n);
	// printf("m is: %d\n", m);
	// printf("optsi is: %d\n", opts->i);
	while (m < n)
	{
		if (opts->i != 0)
			opts->subdir = 1;
		opts->argd = m;
		// printf("checking arg: %s\n", dfile[m]->path);
		// opts->subdir = 1;
		check_arg(opts, dfile[m]->path);
				// free(dfile[m]);
		m++;
	}
	free(dfile);
}

void	check_if_dir(t_opt *opts, char *av, t_file *list, t_file *file)
{
	DIR				*dir;
	struct stat		myst;
	char			*p;

	dir = ft_memalloc(sizeof(DIR));
	p = ft_new_path(opts->hp, av);
	if (stat(p, &myst) == 0 && S_ISDIR(myst.st_mode))
	{
		dir = opendir(opts->hp);
		file->name = ft_strdup(av);
		file->path = ft_strdup(p);
		getstats(&myst, file);
		closedir(dir);
		free(p);
		list->nfiles++;
	}
}