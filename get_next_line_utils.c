/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:45:56 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/12 15:27:29 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*null_cases(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (NULL);
}

static void	cpy_strings(char *dst, char const *s1, char const *s2)
{
	while (*s1)
		*dst++ = *s1++;
	while (*s2)
		*dst++ = *s2++;
	*dst = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_1;
	size_t	len_2;

	ptr = null_cases(s1, s2);
	if (ptr)
		return (ptr);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	ptr = malloc(len_1 + len_2 + 1);
	if (!ptr)
		return (NULL);
	cpy_strings(ptr, s1, s2);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	total;
	char	*ptr;

	total = ft_strlen(s1);
	ptr = malloc(total + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[total] = '\0';
	return (ptr);
}
