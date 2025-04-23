/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babodere <babodere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:38:52 by babodere          #+#    #+#             */
/*   Updated: 2025/04/23 19:54:33 by babodere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    int count;

	if (!str)
		return (0);
    count = 0;
    while (str[count])
        count++;
    return (count);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*array;

	if (n == 0 || !s)
		return ;
	array = (unsigned char *)s;
	while (n--)
		*array++ = 0;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*array;

	if (n == 0 || !s)
		return (NULL);

	array = (unsigned char *) s;
	while (n--)
		*array++ = c;
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	size_t			i;


	s = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ft_memset((dest + i), *(s + i), 1);
		++i;
	}
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	if (!dst || !src || size == 0)
		return 0;

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

int check_retval(char stash[BUFFER_SIZE + 1], char *retval)
{
	int	s_index;
	int	r_index;
	int	line;

    s_index = 0;
    r_index = 0;
    line = 0;
    while (retval[r_index])
    {
        if (line == 1)
        {
            stash[s_index++] = retval[r_index];
            retval[r_index] = '\0';
        }
        if (retval[r_index] == '\n')
            line = 1;
        r_index++;
    }
    stash[s_index] = '\0';
    return (line);
}
