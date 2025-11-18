/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:46:39 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/18 22:17:23 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *saved)
{
	char	*buf;
	ssize_t	bytes;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && (!saved || !ft_strchr(saved, '\n')))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (free(saved), NULL);
		}
		buf[bytes] = '\0';
		tmp = ft_strjoin(saved, buf);
		free(saved);
		saved = tmp;
	}
	free(buf);
	return (saved);
}

static char	*extract_line(char *saved)
{
	char	*line;
	int		i;
	int		len;

	i = 0;
	if (!saved || !saved[0])
		return (NULL);
	while (saved[i] && saved[i] != '\n')
		i++;
	len = i;
	if (saved[i] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (saved[i] && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*trim_saved(char *saved)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
		return (free(saved), NULL);
	new_s = malloc(ft_strlen(saved) - i);
	if (!new_s)
		return (free(saved), NULL);
	i++;
	j = 0;
	while (saved[i])
		new_s[j++] = saved[i++];
	new_s[j] = '\0';
	free(saved);
	return (new_s);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = read_file(fd, saved);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	if (!line)
	{
		free(saved);
		saved = NULL;
	}
	else
		saved = trim_saved(saved);
	return (line);
}

// int main()
// {
//     int fd = open("file.txt", O_RDONLY);
//     char *line;

//     line = get_next_line(fd);
//     printf("1: [%s]\n", line);
//     if (line) printf("len: %zu\n", ft_strlen(line));
//     free(line);

//     line = get_next_line(fd);
//     printf("2: [%s]\n", line);
//     free(line);

//     line = get_next_line(fd);
//     printf("3: [%s]\n", line);
//     free(line);

//     return (0);
// }
