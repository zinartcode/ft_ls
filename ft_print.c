/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:38:20 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/27 20:12:50 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file(t_opt *opts)
{
	ft_putstr(opts->path);
	ft_putchar('\n');
}

void	print_time(time_t *date)
{
	time_t	curr_time;
	char	*f_ctime;
	char	*f_mtime;

	curr_time = time(NULL);
	f_ctime = ctime(&curr_time);
	f_mtime = ctime(date);

	ft_putnstr(&f_mtime[4], 7);

	if (curr_time - *date  > 15780000)
		ft_putnstr(&f_mtime[19], 5);
	else
		ft_putnstr(&f_mtime[11], 5);
}

void	print_total(t_opt *opts, t_file *list)
{
	if (opts->subdir == 1)
	{
		ft_putchar('\n');
		ft_putstr(opts->path);
		ft_putchar(':');
		ft_putchar('\n');
		opts->subdir = 0;
	}
	opts->subdir = 0; //check if needed
	if (opts->is_l == 1)
	{
		if (list->total != 0)
			{
				ft_putstr("total ");
				ft_putnbr(list->total);
			}
		ft_putchar('\n');
	}
}
