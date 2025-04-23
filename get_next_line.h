/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:59 by babodere          #+#    #+#             */
/*   Updated: 2025/04/23 19:56:15 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	    ft_strlen(const char *str);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
int	    check_retval(char stash[BUFFER_SIZE + 1], char *retval);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif