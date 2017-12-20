/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:46:29 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/19 23:48:03 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void check_arg(t_opt *opts, char **av)
{
	DIR	*dir;
	struct stat mystat;
	t_file *list;

	opts->path = *av;
	list = ft_memalloc(sizeof(t_file));
	if(av[0][0] != '-')
	{
		dir = opendir(*av);
		if(stat(opts->path, &mystat) == 0 && S_ISDIR(mystat.st_mode))
		{
			printf("it is a directory: %s\n", opts->path);  //test
			process_args(opts, list, dir);
		}

		else if(stat(opts->path, &mystat) == 0 && S_ISREG(mystat.st_mode))
			printf("it is a file: %s\n", opts->path);  //test
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

char	*ft_new_path(char *original, char *name)
{
	int		len;
	char	*temp;

	len = ft_strlen(original);
	printf("%s\n", name);
	if ((*original) && ((original)[len - 1] != '/'))
		original = ft_strjoin(original, "/");
		temp = ft_strjoin(original, name);
		// printf("path is: %s\n", temp);
		free(original);
		free(temp);
		return(temp);
}

void	process_args(t_opt *opts, t_file *list, DIR *dir)
{
	struct stat mystat;
	struct dirent *sd;
	int	i;
	char	*p;

	i = 0;
	dir  = opendir(opts->path);
	while((sd = readdir(dir)) != NULL)
	{
		p = ft_new_path(opts->path, sd->d_name);
		if ((stat(p, &mystat)) == 0)
		list->total += mystat.st_blocks;
		i++;
	}
	ft_putstr("total ");  //test
	ft_putnbr(list->total);  //test
	ft_putchar('\n');  //test
	ft_putstr("number of files: ");  //test
	ft_putnbr(i);  //test
	ft_putchar('\n');  //test
	closedir(dir);
}

void	check_file(char *n)
{
	n = NULL;
}

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

int main(int ac, char **av)
{
	int		i;
	t_opt	opts;

	// opts = (t_opt*)ft_memalloc(sizeof(t_opt));
	i = 1;
	if (ac == 1)
		print_name();
	if (ac >= 2)
	{
		while(av[i] != '\0')
		{
			// printf("%s\n", av[i]);
			// check_error()  //check if dir and change dir or check if "-" and get flags
			// ft_putstr(av[i]);
			get_flags(&opts, &av[i]);
			check_arg(&opts, &av[i]);
			i++;
		}	
	}
	return 0;
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