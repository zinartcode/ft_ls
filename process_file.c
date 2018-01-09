/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:27:45 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/08 21:46:21 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_file(t_opt *opts, char *f, DIR *dir)
{
	char			*p;
	struct stat		mystat;
	struct dirent	*sd;
	t_file			*file;

	file = ft_memalloc(sizeof(t_file));
	if ((sd = readdir(dir)) != NULL)
	{
		p = ft_new_path(opts->hp, f);
		if ((lstat(p, &mystat)) == 0)
		{
			file->name = ft_strdup(f);
			file->path = ft_strdup(p);
			getstats(&mystat, file);
			if (opts->is_l == 1)
				print_l(file);
			else
			{
				ft_putstr(f);
				ft_putchar('\n');
			}
		}
		free(p);
	}
	free(file);
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
