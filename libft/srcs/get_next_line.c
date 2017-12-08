/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 14:37:08 by azinnatu          #+#    #+#             */
/*   Updated: 2017/12/02 14:59:09 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static t_list		*fd_text(t_list **list, int fd)
{
	t_list			*mem;

	mem = *list;
	while (mem)
	{
		if (fd == (int)mem->content_size)
			return (mem);
		mem = mem->next;
	}
	mem = ft_lstnew("", fd);
	mem->next = *list;
	*list = mem;
	return (mem);
}

static int			text_add(char *str, char **line)
{
	int				i;

	i = 0;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	else
		i = ft_strlen(str);
	*line = ft_strndup(str, i);
	if (str[i] == '\n')
		return (++i);
	return (i);
}

static void			add_link(t_list *list, char *buf, int len)
{
	char			*tmp;

	tmp = list->content;
	list->content = ft_strnjoin(list->content, buf, len);
	free(tmp);
}

static void			text_cut(t_list *list, int len)
{
	char			*str;

	str = list->content;
	list->content = ft_strdup(list->content + len);
	free(str);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list = NULL;
	t_list			*str;
	int				tmp;
	int				len;

	if (fd < 0 || line == NULL || read(fd, buf, 0) || BUFF_SIZE <= 0)
		return (-1);
	str = list;
	list = fd_text(&str, fd);
	while (!ft_strchr(list->content, '\n') && (tmp = read(fd, buf, BUFF_SIZE)))
		add_link(list, buf, tmp);
	len = text_add((char*)list->content, line);
	text_cut(list, len);
	list = str;
	if (len > 0)
		return (1);
	else
		return (0);
}
