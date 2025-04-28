/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:33 by babodere          #+#    #+#             */
/*   Updated: 2025/04/28 03:08:52 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_realloc(char *str, int size)
{
	char	*retval;
	int		str_size;

	if (!str)
		return (malloc(sizeof(char) * size));
	str_size = ft_strlen((const char *)str);
	retval = (char *)malloc(sizeof(char) * (str_size + size));
	if (!retval)
		return (free(str), NULL);
	ft_strcpy((void *)retval, str);
	free(str);
	return (retval);
}

char	*init_retval(char stash[BUFFER_SIZE + 1])
{
	char	*retval;
	int		malloc_size;

	if (stash[0] != '\0')
		malloc_size = ft_strlen(stash) + 1;
	else
		malloc_size = 1;
	retval = (char *)malloc(sizeof(char) * malloc_size);
	if (!retval)
		return (NULL);
	retval[0] = '\0';
	if (stash[0] != '\0')
		retval = (char *)ft_strcpy(retval, stash);
	return (retval);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	stash[1024][BUFFER_SIZE + 1];
	char		*retval;
	int			r;

	r = 1;
	retval = init_retval(stash[fd]);
	if (fd < 0 || fd > 1024 || !retval)
		return (free(retval), stash[fd][0] = 0, NULL);
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		buff[r] = '\0';
		if (r < 0)
			break ;
		retval = ft_realloc(retval, r + 1);
		if (!retval)
			return (stash[fd][0] = 0, NULL);
		ft_strcat(retval, (const char *)buff);
		if (retval[0] == 0)
			return (stash[fd][0] = 0, free(retval), NULL);
		if (check_retval(stash[fd], retval) == 1 || r == 0)
			return (ft_strdup(retval));
	}
	return (stash[fd][0] = 0, free(retval), NULL);
}
