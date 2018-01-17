/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 00:20:18 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/16 00:38:13 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_opt	*opts;
	int		i;

	i = 1;
	opts = ft_memalloc(sizeof(t_file));
	init_opts(opts);
	if (ac >= 2)
	{
		find_files(av, opts, i);
		if (opts->i != 0)
			find_dirs(av, opts, i);
	}
	else if (ac == 1)
		check_arg(opts, opts->path);
	else
		return (1);
	free(opts);
	return (0);
}

void	init_opts(t_opt *opts)
{
	opts->path = ".";
	opts->subdir = 0;
	opts->argf = 0;
	opts->argd = 0;
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
			ft_puterror("ft_ls: ");
			ft_puterror("illegal option -- ");
			ft_puterror(&av[0][i]);
			ft_puterror("\nusage: ft_ls [-Raltr] [file ...]\n");
			exit(1);
		}
	}
}
