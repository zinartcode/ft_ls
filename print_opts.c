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
	// char	*symlink;
	char	buff[512];
	// int		x;

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
	ft_putchar('	');
	ft_putstr(list->name);
	if (list->permissions[0] == 'l')
	{
		// ft_putstr(" -> ");

			readlink(list->name, buff, 512);
			// buff[x] = '\0';
			ft_putstr(" -> ");
			ft_putstr(list->name);
		// symlink = readlink(list);
	// 	if (symlink != NULL)
	// 	{
	// 		printf("%s -> %s", list->name, symlink);
	// 		free(symlink);
	// 	}
	}
	// else
	ft_putchar('\n');	
}

char	*get_symlink_address(t_file *list)
{
	char	*symlink;
	char	*fullpath;

	if ((fullpath = ft_strjoin(list->path, list->name)) == NULL)
		return (NULL);
	if ((symlink = ft_memalloc(PATH_MAX)) == NULL)
	{
		free(fullpath);
		return (NULL);
	}
	if ((readlink(fullpath, symlink, PATH_MAX)) == -1)
	{
		free(symlink);
		free(fullpath);
		return (NULL);
	}
	free(fullpath);
	return (symlink);
}