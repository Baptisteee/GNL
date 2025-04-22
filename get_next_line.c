/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:33 by babodere          #+#    #+#             */
/*   Updated: 2025/04/20 18:45:55 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*retval;
	int		index;

	index = 0;
	while (str[index] != '\n')
		index++;
	retval = (char *) malloc(sizeof(char) * index + 1);
	if (!retval)
		return (NULL);
	ft_strlcpy(retval, str, index);
	free(str);
	return (retval);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*stash;
	int		r;

	r = 1;
	stash = (char *) malloc(sizeof(char) * 1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		stash = ft_export_stash(stash, buff, r);
		if (!stash)
			return (NULL);
		if (is_newline(stash) != -1)
			return (get_line(stash));
	}
	return (NULL);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	(void) ac;
	int	fd = open(av[1], O_RDONLY);
	printf("%s", get_next_line(fd));

	return (0);
}