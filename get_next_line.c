/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:31:45 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/24 20:00:46 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// function that checks about fd and mem alloc
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			read_result;

	// 1. Read until we have a complete line or EOF
	read_result = read_to_buffer(fd, buffer);
	// 2. Check for errors or end of file
	if (read_result == -1)
		return (NULL);
	if (read_result == 0 && buffer[0] == '\0')
		return (NULL);
	// 3. Extract one line from the buffer
	line = extract_line(buffer);
	if (!line)
		return (NULL);
	// 4. Update buffer (remove the extracted line)
	update_buffer(buffer, ft_strlen(line));
	return (line);
}

// returns status code to tell gnl what happend
// > 0 success || 0 end of file || -1 error
int	read_to_buffer(int fd, char *buffer)
{
	int		b_read;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	b_read = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		
		// error
		if (b_read == -1)
			return (-1);
		// end of file
		if (b_read == 0)
			return (0);
		// adds \0 to avoid garbage collection
		// and potential crash
		buf[b_read] = '\0';
		temp = *buffer;
		buffer = ft_strjoin(*buffer, buf);
		
		free(temp);
	}
	return (1);
}

// returns newly allocated string line + \n
// buffer is the pointer to the begining of the string
char	*extract_line(char *buffer)
{
	char	*new_pos;
	size_t	line_len;
	char	*line;

	// find newline if it exists
	new_pos = ft_strchr(buffer, '\n');
	// if the line exists (\n was found)
	if (new_pos)
	{
		line_len = (new_pos - buffer) + 1;
		// new_pos points to '\n' buffer points to begining
		//+1 for \n
	}
	else
	{
		line_len = ft_strlen(buffer);
		// if \n won't be found
	}
	line = ft_substr(buffer, 0, line_len);
	return (line);
}

// it modifies the buffer directly
void	update_buffer(char *buffer, size_t l_len)
{
	size_t	rem_len;
	size_t	i;

	// counts how much data is left after the line
	rem_len = ft_strlen(buffer) - l_len;
	if (rem_len > 0)
	{
		i = 0;
		while (i < rem_len)
		{
			buffer[i] = buffer[l_len + i];
			i++;
		}
	}
	buffer[rem_len] = '\0';
	// null term and clear the rest
}
