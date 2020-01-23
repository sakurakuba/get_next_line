/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksulaima <ksulaima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:47:38 by ksulaima          #+#    #+#             */
/*   Updated: 2019/11/15 22:16:23 by ksulaima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_end(char **str, char **line, const int fd, int k)
{
	char	*temp;
	int		length;

	length = 0;
	while (str[fd][length] != '\0' && str[fd][length] != '\n')
		length++;
	if (str[fd][length] == '\n')
	{
		*line = ft_strsub(str[fd], 0, length);
		temp = ft_strdup(str[fd] + length + 1);
		free(str[fd]);
		str[fd] = temp;
	}
	else if (str[fd][length] == '\0')
	{
		if (k == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int				k;
	static char		*str[255];
	char			buff[BUFF_SIZE + 1];
	char			*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((k = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[k] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (k < 0)
		return (-1);
	if (k == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (check_end(str, line, fd, k));
}
