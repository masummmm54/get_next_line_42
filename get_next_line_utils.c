/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:23:57 by muhakose          #+#    #+#             */
/*   Updated: 2023/11/01 15:00:21 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	size_t	i;
	void	*str;

	total = count * size;
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		((char *)str)[i] = 0;
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (unsigned char)c && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			len;
	size_t		i;
	size_t		j;
	char		*ptr;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		ptr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
