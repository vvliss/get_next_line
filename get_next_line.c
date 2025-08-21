/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:31:45 by wilisson          #+#    #+#             */
/*   Updated: 2025/08/21 22:37:51 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//function that checks about fd and mem alloc
char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	int bytes_read;
	char *line;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	
}

//function that reads BUFFER_SIZE ch by ch till /n or /0
//using strchr
char	*fill_line_buff(int fd, char *leftovers, char *buff)
{
	
}