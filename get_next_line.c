/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:33 by babodere          #+#    #+#             */
/*   Updated: 2025/04/23 22:25:23 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_realloc(char *str, int size)
{
	char	*retval;
	int		str_size;

	if (!str)
		return (malloc(sizeof(char) * size));	
	str_size = ft_strlen((const char *) str);
	retval = (char *) malloc(sizeof(char) * (str_size + size));
	if (!retval)
		return (free(str), NULL);
	ft_bzero(retval, str_size + size);
	ft_memcpy((void *) retval, (const void *) str, str_size);
	free(str);
	str = NULL;
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
	retval = (char *) malloc(sizeof(char) * malloc_size);
	if (!retval)
		return (NULL);
	ft_bzero(retval, malloc_size);
	if (stash[0] != '\0')
		retval = (char *) ft_memcpy(retval, (const char *) stash, malloc_size);
	return (retval);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE];
	static char	stash[1024][BUFFER_SIZE + 1];
	char		*retval;
	int			r;

	if (fd < 0 || fd > 1024)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE);
	r = 1;
	retval = init_retval(stash[fd]);
	if (!retval)
		return (NULL);
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			break ;
		retval = ft_realloc(retval, r + 1);
		if (!retval)
			return (NULL);
		ft_strlcat(retval, (const char *) buff, ft_strlen(retval) + r + 1);
		if (check_retval(stash[fd], retval) == 1)
			return (retval);
		if (r == 0)
			return(retval);
	}
	return (NULL);
}

// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	int	fd;
// 	int	fd2;
	
// 	fd = open(av[1], O_RDONLY);
// 	fd2 = open(av[2], O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd2);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd2);
// 	printf("%s", s);
// 	free(s);
// }