/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 23:59:26 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/13 01:13:14 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_l(t_file *list)
{
	// i = list->nfiles;
	// ft_putstr("total ");
	// ft_putnbr(list->total);
	// ft_putchar('\n');
		ft_putstr(list->permissions);
		ft_putstr("  ");
		ft_putnbr(list->nlinks);
		ft_putstr(" ");
		ft_putstr(list->username);
		ft_putstr("  ");
		ft_putstr(list->groupname);
		ft_putchar(' ');
		ft_putnbr(list->byte_size);
		ft_putchar(' ');
		// print_time(mystat.st_mtimespec);
		// ft_putstr(list->date);
		ft_putnbr(list->date_raw);
		
		ft_putchar(' ');
		ft_putstr(list->name);
		ft_putchar('\n');	
		// ft_putnbr(list->nfiles);
}