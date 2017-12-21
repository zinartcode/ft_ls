/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:54:45 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/20 23:20:37 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_flags(t_opt *opts, char **av)
{
	size_t			i;

	i = ft_strlen(*av);
	// opts->path = ".";
	if(av[0][0] == '-' && av[0][1] != '\0')
	{
		while(--i >= 1)
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
				ft_putstr("\nusage: ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
				exit(1);
			}
		}
		test_opts(opts);
	}
}

void	process_args(t_opt *opts, t_file *list, DIR *dir)
{
	struct stat mystat;
	struct dirent *sd;
	char	*p;
	t_file **file;
	int	i;

	// file = NULL;
	i = 0;
	list->nfiles = 0;
	dir  = opendir(opts->path);
	while((sd = readdir(dir)) != NULL)
	{
		p = ft_new_path(opts->path, sd->d_name);
		if ((stat(p, &mystat)) == 0)
			list->total += mystat.st_blocks;
			list->nfiles++;
	}
		closedir(dir);

	dir  = opendir(opts->path);
	ft_putnbr(sizeof(t_file)); //test
	*file = ft_memalloc(list->nfiles * sizeof(t_file));
	while((sd = readdir(dir)) != NULL)
	{
		
		p = ft_new_path(opts->path, sd->d_name);
		ft_putstr(p);  //test
		ft_putchar('\n'); //test
		if ((stat(p, &mystat)) == 0)
		{
			printf("im here: %s\n %d\n", sd->d_name, i);

			getstats(&mystat, file[i]);
			printf("%s\n", file[i]->username);
		}
		i++;
		free(p);
	}
	ft_putstr("total ");  //test
	ft_putnbr(list->total);  //test
	ft_putchar('\n');  //test
	ft_putstr("number of files: ");  //test
	ft_putnbr(list->nfiles);  //test
	ft_putchar('\n');  //test
	closedir(dir);
}

void check_arg(t_opt *opts, char **av)
{
	DIR	*dir;
	struct stat mystat;
	t_file *list;

	list = ft_memalloc(sizeof(t_file));
	if(av[0][0] != '-')
	{
		opts->path = *av;
		dir = opendir(opts->path);
		if(stat(opts->path, &mystat) == 0 && S_ISDIR(mystat.st_mode))
		{
			printf("it is a directory: %s\n", opts->path);  //test
			process_args(opts, list, dir);
		}

		else if(stat(opts->path, &mystat) == 0 && S_ISREG(mystat.st_mode))
		{
			printf("it is a file: %s\n", opts->path);  //test
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
	printf("%s\n", name);  //test
	if ((*original) && ((original)[len - 1] != '/'))
		original = ft_strjoin(original, "/");
		temp = ft_strjoin(original, name);
		// printf("path is: %s\n", temp);
		free(original);
		// free(temp);
		return(temp);
}