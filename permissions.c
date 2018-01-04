/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:48:17 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/27 20:28:26 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



// void	print_symlink(t_file *list, char *path)
// {
// 	char	*symlink;

// 	if (S_ISLNK(list->st.st_mode))
// 	{
// 		symlink = get_symlink_address(path, list);
// 		if (symlink != NULL)
// 		{
// 			printf(1, " -> %s", symlink);
// 			free(symlink);
// 		}
// 	}
// }

// void		print_permissions(mode_t mode)
// {
// 	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
// 	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
// 	if (mode & S_ISUID)
// 		ft_putchar('S');
// 	else
// 		ft_putchar((mode & S_IXUSR) ? 'x' : '-');
// 	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
// 	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
// 	if (mode & S_ISGID)
// 		ft_putchar('S');
// 	else
// 		ft_putchar((mode & S_IXGRP) ? 'x' : '-');
// 	ft_putchar((mode & S_IROTH) ? 'r' : '-');
// 	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
// 	if (mode & S_ISVTX)
// 		ft_putchar('T');
// 	else
// 		ft_putchar((mode & S_IXOTH) ? 'x' : '-');
// 	ft_putchar(' ');
// }

// void		print_filetype(mode_t mode)
// {
// 	if ((mode & S_IFMT) == S_IFLNK)
// 		ft_putchar('l');
// 	else if ((mode & S_IFMT) == S_IFDIR)
// 		ft_putchar('d');
// 	else if ((mode & S_IFMT) == S_IFCHR)
// 		ft_putchar('c');
// 	else if ((mode & S_IFMT) == S_IFBLK)
// 		ft_putchar('b');
// 	else if ((mode & S_IFMT) == S_IFSOCK)
// 		ft_putchar('s');
// 	else if ((mode & S_IFMT) == S_IFIFO)
// 		ft_putchar('f');
// 	else if ((mode & S_IFMT) == S_IFREG)
// 		ft_putchar('-');
// }

// void	read_files(char *path, t_file *list, t_opt *opts)
// {
// 	DIR				*dir;
// 	struct dirent	*ent;
// 	struct stat 	mystat;
// 	t_file			*n_list;

// 	dir = NULL;
// 	ent = NULL;
// 	n_list = list;
// 	if ((dir = opendir(path)) == NULL)
// 		ft_putstr("read_file: Failed to open Dir.");
// 	while ((ent = readdir(dir)) != NULL)
// 	{
// 		if (opts->is_a == 0 && ent->d_name[0] == '.')
// 			continue;
// 		if (!(n_list = (t_file *)malloc(sizeof(t_file))))
// 			ft_putstr("read_files: failed to malloc n_file.");
// 		getstats(&mystat, n_list);
// 		n_list->name = ent->d_name;
// 		 ft_putstr(ent->d_name);  //test
// 		 ft_putchar('\n');  //test

// 	}
// 	free(ent);
// 	closedir(dir);
// }