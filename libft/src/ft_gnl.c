/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 03:40:28 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/28 14:32:15 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** This function read 1 line of the given file descriptor.
** You can adjust the buff size with the macro GNL_BUFF_SIZE.
** Return:	1 if read is successfull.
** 			0 if the function have reached the end of the file.
**			-1 if there was read error.
*/

static t_fd		*create_fd(t_fd *file, int fd)
{
	t_fd		*tmp;
	t_fd		*new;

	new = (t_fd*)malloc(sizeof(t_fd));
	if (new == NULL)
		return (NULL);
	new->strt = ft_strnew(GNL_BUFF_SIZE + 1);
	new->buff = new->strt;
	new->fd = fd;
	if (file)
	{
		new->next = file;
		tmp = file;
		while (tmp->next != file)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		new->next = new;
	return (new);
}

static t_fd		*find_fd(t_fd *file, int fd)
{
	t_fd		*tmp;

	tmp = file;
	if (file)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->next)
			tmp = tmp->next;
		while (tmp != file)
		{
			if (tmp->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (create_fd(file, fd));
}

static int		readnext(t_fd *file)
{
	int			ret;

	ft_bzero(file->strt, GNL_BUFF_SIZE);
	ret = read(file->fd, file->strt, GNL_BUFF_SIZE);
	file->buff = file->strt;
	return (ret);
}

static char		*get_pos(t_fd *file, char **line)
{
	char		*ret;
	char		*tmp;

	ret = ft_strchr(file->buff, '\n');
	if (ret != NULL)
		*ret = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, file->buff);
	free(tmp);
	return (ret);
}

int				ft_gnl(int const fd, char **line)
{
	static t_fd	*file = NULL;
	char		*pos;
	int			ret;

	file = find_fd(file, fd);
	if (GNL_BUFF_SIZE <= 0 || file == NULL || !line)
		return (-1);
	*line = ft_strnew(1);
	ret = 1;
	if (*(file->buff) == '\0')
		ret = readnext(file);
	while (ret > 0)
	{
		pos = get_pos(file, line);
		if (pos == NULL)
			ret = readnext(file);
		else
		{
			file->buff = pos + 1;
			return (1);
		}
	}
	if (**line != '\0')
		ret = 1;
	return (ret);
}
