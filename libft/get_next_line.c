/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmazzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 02:55:42 by lmazzi            #+#    #+#             */
/*   Updated: 2017/05/06 22:20:31 by lmazzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ist	*ft_new_list(int fd)
{
	t_ist	*nlist;

	nlist = (t_ist*)malloc(sizeof(*nlist));
	if (!nlist)
		return (NULL);
	nlist->next = NULL;
	nlist->pre = NULL;
	nlist->fd = fd;
	nlist->ret = 0;
	nlist->line = NULL;
	nlist->old = NULL;
	return (nlist);
}

t_ist	*ft_readline(char **line, t_ist *li, char *addn)
{
	if (addn && li->ret != 0)
	{
		*addn = '\0';
		if (*(addn + 1) != '\0')
		{
			if (li->old)
				free(li->old);
			li->old = ft_strdup(addn + 1);
		}
		return (li);
	}
	if (li->line != NULL && li->ret == 0)
	{
		li->ret = 1;
		*line = ft_strdup(li->line);
		free(li->line);
		li->line = NULL;
		return (li);
	}
	return (li);
}

t_ist	*ft_read_it(const int fd, char **line, t_ist *li)
{
	char	*tmp;
	char	*addn;
	char	tab[BUFF_SIZE + 1];
	int		yes;

	yes = 0;
	while (yes == 0)
	{
		li->ret = read(fd, tab, BUFF_SIZE);
		if (!(tab[li->ret] = '\0') && li->line != NULL && li->ret == 0)
			return (ft_readline(line, li, addn));
		if (li->ret == 0 || li->ret == -1)
			return (li);
		tmp = li->line;
		if ((li->line = ft_strjoin(tmp, tab)) && tmp)
			free(tmp);
		if (li->line == NULL)
			li->line = ft_strdup(tab);
		if (li->line != NULL && (addn = ft_strchr(li->line, '\n')) != NULL)
			yes = 1;
	}
	if ((li->ret = 1) && addn)
		li = ft_readline(line, li, addn);
	*line = ft_strdup(li->line);
	return (li);
}

t_ist	*ft_check_old(const int fd, char **line, t_ist *li)
{
	char *addn;
	char *tmp;

	if (li->old == NULL && (li = ft_read_it(fd, line, li)))
		return (li);
	if (ft_strchr(li->old, '\n'))
	{
		addn = ft_strchr(li->old, '\n');
		tmp = li->old;
		*addn = '\0';
		if (*(addn + 1) != '\0')
			li->old = ft_strdup(addn + 1);
		*line = ft_strdup(tmp);
		if (*(addn + 1) == '\0')
			li->old = NULL;
		li->ret = 1;
		return (li);
	}
	li->line = ft_strdup(li->old);
	free(li->old);
	li->old = NULL;
	li = ft_read_it(fd, line, li);
	return (li);
}

int		get_next_line(const int fd, char **line)
{
	static t_ist	*li;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (li == NULL)
		li = ft_new_list(fd);
	while (li->pre != NULL)
		li = li->pre;
	while (li->next && li->fd != fd)
		li = li->next;
	if (li->next == NULL && li->fd != fd)
	{
		li->next = ft_new_list(fd);
		li->next->pre = li;
		li = li->next;
	}
	li = ft_check_old(fd, line, li);
	if (li->line)
		free(li->line);
	li->line = NULL;
	return (li->ret);
}
