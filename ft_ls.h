/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:33:16 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/29 23:26:00 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS_H
#define	FT_LS_H
#include	"libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <limits.h>

typedef struct		s_opt
{
	int				flag;
	int				i;
	int				subdir;
	int				is_l;
	int				is_upper_r;
	int				is_a;
	int				is_lower_r;
	int				is_t;
	char			*path;
	char			*hp;
}					t_opt;

typedef struct		s_file
{
	int				isdir;
	int				nfiles;
	char			*path;
	char			permissions[11];
	int				nlinks;
	char			*username;
	char			*groupname;
	int				byte_size;
	int				block_size;
	time_t			date_raw;
	int				total;
	t_list			*sub_dirs;
	char			*name;
	time_t			date;
}					t_file;

int					main(int ac, char **av);
void				get_args(char **av, t_opt *opts, int i);
int					ok_to_recurse(char *path);
void				init_opts(t_opt *opts);
void				print_name(t_file *list);
void				print_time(time_t *date);
void				print_l(t_file *list);
void				print_total(t_opt *opts, t_file *list);
void				print_lnk(t_file *list);
void				sort_files(t_opt *opts, t_file *list, t_file **file);
void				sort_ar(t_file **list, int s);
void				sort_ar_rev(t_file **list, int s);
void				sort_date(t_file **list, int s);
void				sort_date_rev(t_file **list, int s);
void				clear_file(t_file *file);
char				*mod_time(time_t mtime);
void				get_flags(t_opt *opts, char **av);
void				check_arg(t_opt *opts, char *av);
void				process_l(t_opt *opts, t_file *list, t_file **file);
void				process_upper_r(t_opt *opts, t_file *list, t_file **file);
void				process_args(t_opt *opts, DIR *dir);
void				process_args2(t_opt *opts, t_file *list, DIR *dir);
void				getstats(struct stat *mystat, t_file *list);
void				get_type(struct stat *mystat, t_file *list);
char				*ft_new_path(char *original, char *name);

#endif
