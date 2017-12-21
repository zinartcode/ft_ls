/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:46:29 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/20 17:37:30 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
	int		i;
	t_opt	opts;

	// opts = (t_opt*)ft_memalloc(sizeof(t_opt));
	opts.path = ".";
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

// modify Makefile to compile GCC, remove debugging