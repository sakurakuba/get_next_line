/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksulaima <ksulaima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 22:21:16 by ksulaima          #+#    #+#             */
/*   Updated: 2019/11/15 22:16:10 by ksulaima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>

int		get_next_line(const int fd, char **line);

#endif
