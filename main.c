/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:46:29 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/29 00:57:03 by azinnatu         ###   ########.fr       */
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
			check_arg(&opts, &av[i]);
		}
		i++;
		}
		if (flag == 0)
			check_arg(&opts, &cur);
		if (ac == 1)
			check_arg(&opts, &cur);
	}
	return (0);
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