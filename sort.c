/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:19:09 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/13 01:20:21 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		quicksort(char **tab, int size)
{
	char		*pivot;
	char		*temp;
	int			lower;
	int			upper;

	if (size < 2)
		return ;
	lower = 0;
	upper = size - 1;
	pivot = tab[upper];
	while (lower < upper)
	{
		while (ft_strcmp(tab[lower], pivot) < 0)
			lower++;
		while (ft_strcmp(tab[upper], pivot) > 0)
			upper--;
		temp = tab[lower];
		tab[lower] = tab[upper];
		tab[upper] = temp;
	}
	quicksort(tab, lower);
	quicksort(&tab[lower + 1], size - lower - 1);
}

void  sort_list(t_list *lst)
{
    int     swap;
    t_list  *tmp;
    int data_tmp;

    swap = 1;
    // if (lst == 0)
    //     exit;
    while (swap)
    {
        swap = 0;
        tmp = lst;
        while (tmp->next)
        {
            if (tmp->data >= tmp->next->data)
            {
                data_tmp = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = data_tmp;
                swap = 1;
            }
            tmp = tmp->next;
        }
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