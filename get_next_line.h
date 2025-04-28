/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:59 by babodere          #+#    #+#             */
/*   Updated: 2025/04/25 19:46:11 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		check_retval(char stash[BUFFER_SIZE + 1], char *retval);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *s);
char	*ft_strcat(char *dst, const char *src);

#endif
