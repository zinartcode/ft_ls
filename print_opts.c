/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 23:59:26 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/27 20:25:55 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void print_name(t_file *list)
{
	ft_putstr(list->name);
	ft_putchar('\n');	
}

void print_l(t_file *list)
{

	ft_putstr(list->permissions);
	ft_putstr("  ");
	ft_putnbr(list->nlinks);
	ft_putstr(" ");
	ft_putstr(list->username);
	ft_putstr("  ");
	ft_putstr(list->groupname);
	ft_putchar('	');
	ft_putnbr(list->byte_size);
	ft_putchar('	');
	print_time(&list->date_raw);
	ft_putchar(' ');
	ft_putstr(list->name);
	if (list->permissions[0] == 'l')
		ft_print_lnk(list);
	ft_putchar('\n');	
}

void	ft_print_lnk(t_file *list)
{
	char	*lnkcontent;
	int		ret;
	int		size;

		size = 1024;
		if ((lnkcontent = (char *)ft_memalloc(sizeof(char) * (size))) == NULL)
			ft_putstr("error");
		// printf("%s\n", list->path);
		ret = readlink(list->path, lnkcontent, size);
		lnkcontent[ret] = '\0';
		ft_putstr(" -> ");
		ft_putstr(lnkcontent);
		ft_bzero(lnkcontent, size);
}