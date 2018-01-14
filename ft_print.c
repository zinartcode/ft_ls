/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:38:20 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/11 23:56:35 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*mod_time(time_t mtime)
{
	time_t	curr_time;
	char	*f_mtime;
	char	*t1;
	char	*t2;
	char	*tf;

	t1 = NULL;
	t2 = NULL;
	tf = NULL;
	time(&curr_time);
	f_mtime = ctime(&mtime);
	ft_strncat(t1, &f_mtime[4], 7);
	if (curr_time - mtime > 15552000)
		ft_strncat(t2, &f_mtime[19], 5);
	else
		ft_strncat(t2, &f_mtime[11], 5);
	tf = ft_strjoin(t1, t2);
	return (tf);
}

void		print_time(time_t *date)
{
	time_t	curr_time;
	char	*f_ctime;
	char	*f_mtime;

	curr_time = time(NULL);
	f_ctime = ctime(&curr_time);
	f_mtime = ctime(date);
	ft_putnstr(&f_mtime[4], 7);
	if (curr_time - *date > 115552000)
		ft_putnstr(&f_mtime[19], 5);
	else
		ft_putnstr(&f_mtime[11], 5);
}

void		print_total(t_opt *opts, t_file *list)
{
	// printf("opts->subdir is: %d\n", opts->subdir);
	// printf("opts->argf is: %d\n", opts->argf);
	// printf("opts->i is: %d\n", opts->i);
	// printf("opts->argd is: %d\n", opts->argd);
	// printf("list->nfiles is: %d\n", list->nfiles);
	// printf("list->isdir is: %d\n", list->isdir);
	if (opts->subdir == 1) //&& list->nfiles != 0)
	{
		if (opts->is_upper_r == 0 && (opts->argf != 0 || opts->i != 0))
		{
			if (opts->argd != 0 || opts->argf != 0)
				ft_putchar('\n');
			ft_putstr(&opts->path[2]);
			ft_putchar(':');
			ft_putchar('\n');
		}
		else //if (opts->argf == 0 || opts->argd == 0)
		{
			if (opts->argd != 0)
				ft_putchar('\n');
			ft_putstr(opts->path);
			ft_putchar(':');
			ft_putchar('\n');
		}
	}
	if (opts->is_l == 1 && list->isdir != 0)
	{
		if (list->nfiles != 0) // && opts->subdir != 0)
		{
			ft_putstr("total ");
			ft_putnbr(list->total);
			ft_putchar('\n');
		}
	}
	opts->subdir = 0;
}

void		print_l(t_file *list)
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
		print_lnk(list);
	ft_putchar('\n');
}

void		print_lnk(t_file *list)
{
	char	*lnkcontent;
	int		ret;
	int		size;

	size = 1024;
	if ((lnkcontent = (char *)ft_memalloc(sizeof(char) * (size))) == NULL)
		ft_putstr("error");
	ret = readlink(list->path, lnkcontent, size);
	lnkcontent[ret] = '\0';
	ft_putstr(" -> ");
	ft_putstr(lnkcontent);
	ft_bzero(lnkcontent, size);
}
