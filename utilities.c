/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 23:43:54 by azinnatu          #+#    #+#             */
/*   Updated: 2018/01/17 17:28:20 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lserror(char *str)
{
	int		n;

	n = ft_strlen(str);
	while (str[n] != '/')
		n--;
	write(2, "ft_ls: ", 7);
	if (n > 0)
	{
		while (str[n++])
			write(2, &str[n], 1);
		write(2, ": ", 2);
	}
	else if (n <= 0)
	{
		n = 0;
		while (str[n])
		{
			write(2, &str[n], 1);
			n++;
		}
		write(2, ": ", 2);
	}
}

void		ft_puterror(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

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
	if (curr_time - mtime > 15724800)
		ft_strncat(t2, &f_mtime[19], 5);
	else
		ft_strncat(t2, &f_mtime[11], 5);
	tf = ft_strjoin(t1, t2);
	return (tf);
}

char		*ft_new_path(char *original, char *name)
{
	int		len;
	char	*temp;
	char	*t;

	len = ft_strlen(original);
	if ((*original) && ((original)[len - 1] != '/'))
	{
		t = ft_strjoin(original, "/");
		temp = ft_strjoin(t, name);
		free(t);
	}
	else
		temp = ft_strjoin(original, name);
	return (temp);
}
