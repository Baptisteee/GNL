/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:52:32 by babodere          #+#    #+#             */
/*   Updated: 2025/04/20 11:22:42 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	src_size;

	index = 0;
	src_size = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (src_size);
	while (src[index] && index < size - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (src_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen >= size)
		return (srclen + size);
	while (src[i] && i < size - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

int	is_newline(char *stash)
{
	int	index;

	index = 0;
	while (stash[index])
	{
		if (stash[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_export_stash(char *stash, char buff[BUFFER_SIZE], int expand)
{
	char	*new_stash;
	int		stash_size;

	stash_size = ft_strlen(stash);
	new_stash = (char *) malloc(sizeof(char) * (stash_size + expand + 1));
	if (!new_stash)
		return (NULL);
	ft_strlcpy(new_stash, (const char *) stash, stash_size);
	ft_strlcat(new_stash, (const char *) buff, expand + 1);
	free(stash);
	return (new_stash);
}