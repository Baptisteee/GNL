/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:59 by babodere          #+#    #+#             */
/*   Updated: 2025/04/20 13:50:28 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 256

#endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		is_newline(char *stash);
char	*get_next_line(int fd);
char	*ft_export_stash(char *stash, char buff[BUFFER_SIZE], int expand);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif