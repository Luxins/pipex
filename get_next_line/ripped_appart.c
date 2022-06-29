/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripped_appart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:01:49 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/25 15:01:54 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(char	*str, int lenght)
{
	int	i;

	i = 0;
	while (i <= lenght)
	{
		str[i] = 0;
		i++;
	}
}

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

static char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joined;

	if (!s1)
	{
		joined = malloc(sizeof(char) * (ft_strlen(s2) + 1));
		copier(joined, s2, 0, 1);
		return (joined);
	}
	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (joined == 0)
		return (NULL);
	i = copier(joined, s1, 0, 0);
	j = 0;
	while (s2[j])
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[i] = 0;
	free(s1);
	return (joined);
}

/**
 * @brief Reads the appropriate number of blocks.
 *
 * @param fd
 * @param cumulative The pruned cumulative value of the previous read
 * @return char* The new appropriate cumulative.
 */
char	*reader(int fd, char *cumulative)
{
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];

	bytes = 1;
	while (!ft_strchr(cumulative, '\n'))
	{
		ft_bzero(buffer, BUFFER_SIZE);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break ;
		cumulative = ft_strjoin(cumulative, buffer);
	}
	return (cumulative);
}
