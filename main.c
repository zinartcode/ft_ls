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

int main(int ac, char **av)
{
	int		i;
	int		flag;
	t_opt	opts;
	char	*cur;

	// opts = (t_opt*)ft_memalloc(sizeof(t_opt));
	opts.path = ".";
	opts.subdir = 0;
	i = 1;
	flag = 0;
	cur = ".";
	if (ac >= 2)
	{
		while(av[i] != '\0')
		{
			if (av[i][0] == '-' && av[i][1] != '\0')
			get_flags(&opts, &av[i]);
		if (av[i][0] != '-')
		{
			flag  = 1;
			check_arg(&opts, av[i]);
			opts.subdir = 1;
		}
		i++;
		}
	}
	if (flag == 0)
		check_arg(&opts, cur);
	else if (ac == 1)
		check_arg(&opts, cur);
	return (0);
}

void	clear_file(t_file *file)
{
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

void	test_opts(t_opt *opts)  // don't forget to delete ! ! !
{
	printf("l is %d\n", opts->is_l);
	printf("R is %d\n", opts->is_upper_r);
	printf("r is %d\n", opts->is_lower_r);
	printf("a is %d\n", opts->is_a);
	printf("t is %d\n", opts->is_t);
	printf("my dir: %s\n", opts->path);
}

// modify Makefile to compile GCC, remove debugging