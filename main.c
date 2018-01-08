/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:46:29 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/29 22:20:03 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_opt	*opts;
	int i;

	i = 1;
	opts = ft_memalloc(sizeof(t_file));
	init_opts(opts);
		if(ac >= 2)
			get_args(av, opts, i);
		if (ac == 1)
			check_arg(opts, opts->path);
		else
			return(1);
		free(opts);
		return (0);
}

void	get_args(char **av, t_opt *opts, int i)
{
	while(av[i] != '\0')
	{
		if (av[i][0] == '-' && av[i][1] != '\0')
		{
			get_flags(opts, &av[i]);
		}
		if (av[i][0] != '-' && av[i][0] != '\0')
		{
			opts->path = *av;
			opts->flag  = 1;
			check_arg(opts, av[i]);
			opts->subdir = 1;
		}
		i++;
	}
	if (opts->flag == 0)
		check_arg(opts, opts->path);
}

void	init_opts(t_opt *opts)
{
	opts->path = ".";
	opts->subdir = 0;
	opts->i = 0;
	opts->flag = 0;
	opts->hp = ".";
	opts->is_l = 0;
	opts->is_upper_r = 0;
	opts->is_lower_r = 0;
	opts->is_a = 0;
	opts->is_t = 0;
}

void	get_flags(t_opt *opts, char **av)
{
	size_t			i;

	i = ft_strlen(*av);
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
			ft_putstr("\nusage: ft_ls [-Raltr] [file ...]\n");
			exit(1);
		}
	}
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
