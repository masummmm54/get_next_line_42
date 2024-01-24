/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakose <muhakose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:30:52 by muhakose          #+#    #+#             */
/*   Updated: 2023/11/03 13:44:31 by muhakose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buff_to_line(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*readyfornext(char *s)
{
	char	*temp;
	int		i;
	int		newlen;
	int		delete;

	newlen = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	delete = i + 1;
	while (s[i++])
		newlen++;
	temp = malloc (newlen + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (newlen > 0)
	{
		temp[i++] = s[delete++];
		newlen--;
	}
	temp[i] = '\0';
	free(s);
	return (temp);
}

char	*line_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_text(char *s, int fd)
{
	int		byte_size;
	char	*buf;

	if (!s)
		s = ft_calloc(1, 1);
	byte_size = 1;
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (byte_size > 0)
	{
		byte_size = read(fd, buf, BUFFER_SIZE);
		buf[byte_size] = '\0';
		s = buff_to_line(s, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	if (byte_size <= 0 && s[0] == '\0')
	{
		free(s);
		return (NULL);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*all_line[OPEN_MAX];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(all_line[fd]);
		all_line[fd] = NULL;
		return (NULL);
	}
	all_line[fd] = read_text(all_line[fd], fd);
	if (all_line[fd] == NULL || ft_strlen(all_line[fd]) == 0)
	{
		if (all_line[fd] != NULL)
		{
			free(all_line[fd]);
			all_line[fd] = NULL;
		}
		all_line[fd] = NULL;
		return (NULL);
	}
	next_line = line_line(all_line[fd]);
	all_line[fd] = readyfornext(all_line[fd]);
	return (next_line);
}

/* int main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	
	if (fd < 0)
	{
		perror("Error opening file");
		return 1;
	}



	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	// line = get_next_line(fd);
	// printf ("%s", line);
	// free(line);

	close(fd);
	return 0;
} */
