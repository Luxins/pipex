/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:42:50 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/25 14:53:32 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/**
 * @brief Counts.
 *
 * @param c string
 * @return count
 */
static size_t	ft_strlen(const char *c)
{
	size_t	count;

	count = 0;
	while (*c)
	{
		count++;
		c++;
	}
	return (count);
}

char	*cutter(const char *cumulative)
{
	char	*line;
	int		j;

	line = malloc(sizeof(char) * (ft_strlen(cumulative) + 1));
	j = 0;
	while (cumulative[j] && cumulative[j] != '\n')
	{
		line[j] = cumulative[j];
		j++;
	}
	if (cumulative[j] == '\n')
	{
		line[j] = '\n';
		line[j + 1] = 0;
		return (line);
	}
	line[j] = 0;
	return (line);
}

int	copier(char *dest, const char *src, int dest_start, int terminate)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[dest_start] = src[i];
		i++;
		dest_start++;
	}
	if (terminate)
		dest[dest_start] = 0;
	return (dest_start);
}
/**
 * @brief mallocs a joined null-terminated string.
 *
 * @param[in] s1 first part
 * @param s2 the second part
 * @return char* return
 */
// char	*ft_strjoin(char *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*joined;

// 	if (!s1)
// 	{
// 		joined = malloc(sizeof(char) * (ft_strlen(s2) + 1));
// 		i = 0;
// 		while (s2[i])
// 		{
// 			joined[i] = s2[i];
// 			i++;
// 		}
// 		joined[i] = 0;
// 		return (joined);
// 	}
// 	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (joined == 0)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		joined[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		joined[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	joined[i] = 0;
// 	free(s1);
// 	return (joined);
// }

/**
 * @brief Finds first occurence
 *
 * @param s String
 * @param c Character
 * @return char* (The pointer to the occurence)
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}
