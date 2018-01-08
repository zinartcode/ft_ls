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

void	sort_files(t_opt *opts, t_file *list, t_file **file, int i)
{
	i = 0;
	sort_ar(file, list->nfiles);
	if (opts->is_lower_r == 1)
		sort_ar_rev(file, list->nfiles);
	if (opts->is_t == 1)
		sort_date(file, list->nfiles);
	if (opts->is_t == 1 && opts->is_lower_r == 1)
		sort_date_rev(file, list->nfiles);
	if (opts->is_l == 0)
	{
		if (opts->is_upper_r == 1)
			print_total(opts, list);
		while (i < list->nfiles)
		{
			print_total(opts, list);
			ft_putstr(file[i]->name);
			ft_putchar('\n');
			i++;
		}
	}
	if (opts->is_l == 1)
		process_l(opts, list, file);
	if (opts->is_upper_r == 1)
		process_upper_r(opts, list, file);
}

void	sort_ar(t_file **list, int s)
{
	int		j;
	int		i;
	t_file	*temp;

	i = 1;
	j = 0;
	while (i < s)
	{
		j = i - 1;
		while (j >= 0 && ft_strcmp(list[j + 1]->name, list[j]->name) < 0)
		{
			temp = list[j + 1];
			list[j + 1] = list[j];
			list[j] = temp;
			j--;
		}
		i++;
	}
}

void	sort_ar_rev(t_file **list, int s)
{
	int		j;
	int		i;
	t_file	*temp;

	i = 1;
	j = 0;
	while (i < s)
	{
		j = i - 1;
		while (j >= 0 && ft_strcmp(list[j]->name, list[j + 1]->name) < 0)
		{
			temp = list[j + 1];
			list[j + 1] = list[j];
			list[j] = temp;
			j--;
		}
		i++;
	}
}

void	sort_date(t_file **list, int s)
{
	int		j;
	int		i;
	t_file	*temp;

	i = 1;
	j = 0;
	while (i < s)
	{
		j = i - 1;
		while (j >= 0 && list[j + 1]->date_raw > list[j]->date_raw)
		{
			temp = list[j + 1];
			list[j + 1] = list[j];
			list[j] = temp;
			j--;
		}
		i++;
	}
}

void	sort_date_rev(t_file **list, int s)
{
	int		j;
	int		i;
	t_file	*temp;

	i = 1;
	j = 0;
	while (i < s)
	{
		j = i - 1;
		while (j >= 0 && list[j + 1]->date_raw < list[j]->date_raw)
		{
			temp = list[j + 1];
			list[j + 1] = list[j];
			list[j] = temp;
			j--;
		}
		i++;
	}
}
