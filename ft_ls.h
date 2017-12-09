/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:33:16 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/09 15:29:20 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H
#include "libft/includes/libft.h"
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

typedef struct		s_file
{
	char			*name;
	struct stat		mystat;
	struct s_file	*next;
	struct dirent	*sd;
}					t_file;

void				print_name();
void				print_time();
void				print_user_group(struct stat mystat);
void				print_permissions(mode_t mode);
void				print_filetype(mode_t mode);
void				total_size(void);
int					usage(void);

#endif