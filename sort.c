/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:19:09 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/27 00:41:29 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_files(t_opt *opts, t_file *list, t_file **file)
{
	int	i;

	i = 0;
	sort_ar(file, list->nfiles);
	if(opts->is_lower_r == 1 && opts->is_t == 0)
		sort_ar_rev(file, list->nfiles);
	if(opts->is_t == 1)
		sort_date(file, list->nfiles);
	if(opts->is_t == 1 && opts->is_lower_r == 1)
		sort_date_rev(file, list->nfiles);
	if(opts->is_l == 1)
	{
		ft_putstr("total ");
		ft_putnbr(list->total);
		ft_putchar('\n');
		while (i < list->nfiles)
		{
		print_l(file[i]);
		i++;
		}
	}
	if(opts->is_l == 0)
	{
		while (i < list->nfiles)
		{
		print_name(file[i]);
		i++;
		}
	}
}

void	sort_ar(t_file **list, int s)
{
    int j;
    int i;
    t_file *temp;

    i = 1;
    j = 0;
    while(i < s)
    {
        j = i - 1;
        while( j >= 0 && ft_strcmp( list[j+1]->name, list[j]->name ) < 0 )
        {
            temp =  list[j + 1];
            list[j+1] = list[j];
            list[j] = temp;
            j--;
        }
        i++;
    }
}

void	sort_ar_rev(t_file **list, int s)
{
    int j;
    int i;
    t_file *temp;

    i = 1;
    j = 0;
    while(i < s)
    {
        j = i - 1;
        while( j >= 0 && ft_strcmp( list[j]->name, list[j + 1]->name ) < 0 )
        {
            temp =  list[j + 1];
            list[j+1] = list[j];
            list[j] = temp;
            j--;
        }
        i++;
    }
}

void	sort_date(t_file **list, int s)
{
    int j;
    int i;
    t_file *temp;

    i = 1;
    j = 0;
    while(i < s)
    {
        j = i - 1;
        while( j >= 0 && list[j+1]->date_raw > list[j]->date_raw)
        {
            temp =  list[j + 1];
            list[j+1] = list[j];
            list[j] = temp;
            j--;
        }
        i++;
    }
}

void	sort_date_rev(t_file **list, int s)
{
    int j;
    int i;
    t_file *temp;

    i = 1;
    j = 0;
    while(i < s)
    {
        j = i - 1;
        while( j >= 0 && list[j+1]->date_raw > list[j]->date_raw)
        {
            temp =  list[j + 1];
            list[j+1] = list[j];
            list[j] = temp;
            j--;
        }
        i++;
    }
}

char	*mod_time(time_t mtime)
{
	time_t curr_time;
	char	*f_mtime;
	char	*t1;
	char	*t2;
	char	*tf;
	// int		i;

	// ft_putstr("i'm here");

	t1 = NULL;
	t2 = NULL;
	tf = NULL;
	time(&curr_time);
	f_mtime = ctime(&mtime);
	// ft_putnbr(curr_time);
	// ft_putchar('\n');
	// ft_putnbr(mtime);
	// ft_putchar('\n');

	ft_strncat(t1, &f_mtime[4], 7);
	if (curr_time - mtime  > 15780000)
	ft_strncat(t2, &f_mtime[19], 5);
	else
	ft_strncat(t2, &f_mtime[11], 5);
	tf = ft_strjoin(t1, t2);
	return(tf);
}