/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:46:29 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/18 20:54:47 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void check_arg(t_opt *opts, char **av)
{
	DIR	*dir;
	struct	dirent *sd;
	// char	*name;
	t_file *list;

	list = ft_memalloc(sizeof(t_file));
	if(av[0][0] != '-')
	{
		if((dir = opendir(*av)) == NULL)
		{
			ft_putstr("ft_ls: ");
			ft_putstr(*av);
			ft_putstr(": No such file or directory\n");
			exit(1);
		}
		if((sd = readdir(dir)) != NULL)
		{
			// name = sd->d_name;
			// printf("name is %s\n", name);
			opts->path = *av;

			test_opts(opts);  //test
			// check_file(char *n);  //after storing names
		}
	}


	 			// test_opts(opts);
	 	// else
			// ft_putstr("Invalid option for dir"); //check if dir
}

void	check_file(char *n)
{
	n = NULL;
}

void	get_flags(t_opt *opts, char **av)
{
	size_t			i;

	i = ft_strlen(*av);
	opts->path = ".";
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
	}
			// test_opts(opts);
}

int main(int ac, char **av)
{
	int		i;
	t_opt	opts;

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
			// usage(av);
			i++;
		}
		// ft_putstr("ac >=2, i is ");  //test
		// ft_putnbr(i);				//test
		// ft_putchar('\n');			//test		
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