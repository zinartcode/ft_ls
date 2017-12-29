/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:19:09 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/29 01:33:03 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
        while( j >= 0 && list[j+1]->date_raw < list[j]->date_raw)
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

	t1 = NULL;
	t2 = NULL;
	tf = NULL;
	time(&curr_time);
	f_mtime = ctime(&mtime);
	ft_strncat(t1, &f_mtime[4], 7);
	if (curr_time - mtime  > 15780000)
	ft_strncat(t2, &f_mtime[19], 5);
	else
	ft_strncat(t2, &f_mtime[11], 5);
	tf = ft_strjoin(t1, t2);
	return(tf);
}