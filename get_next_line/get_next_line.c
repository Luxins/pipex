/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:41:21 by ljahn             #+#    #+#             */
/*   Updated: 2022/06/25 15:00:58 by ljahn            ###   ########.fr       */
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

char	*updater(char *cumulative)
{
	int		i;
	int		j;
	char	*new_cumulative;

	new_cumulative = malloc(sizeof(char) * (ft_strlen(cumulative) + 1));
	if (!new_cumulative)
		return (NULL);
	i = 0;
	while (cumulative[i] && cumulative[i] != '\n')
		i++;
	if (cumulative[i] == 0)
	{
		free(cumulative);
		free(new_cumulative);
		return (NULL);
	}
	i++;
	j = 0;
	while (cumulative[i - 1])
		new_cumulative[j++] = cumulative[i++];
	new_cumulative[j] = 0;
	if (cumulative)
		free(cumulative);
	return (new_cumulative);
}

char	*get_next_line(int fd)
{
	char static	*cumulative;
	char		*line;

	if (fd < 0 || fd > 10240)
		return (NULL);
	cumulative = reader(fd, cumulative);
	if (!cumulative)
	{
		return (NULL);
	}
	if (cumulative[0] == 0)
	{
		free(cumulative);
		return (NULL);
	}
	line = cutter(cumulative);
	cumulative = updater(cumulative);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line1;
// 	char	*line2;
// 	// char	*line3;
// 	// char	*line4;
// 	// char	*line5;

// 	fd = open("bacon", O_RDWR);
// 	line1 = get_next_line(fd);
// 	line2 = get_next_line(fd);
// 	// line3 = get_next_line(fd);
// 	// line4 = get_next_line(fd);
// 	// line5 = get_next_line(fd);
// 	printf("%s", line1);
// 	if (line2 == NULL)
// 		printf("ACTUALLY A NULL.");
// 	// printf("%s", line3);
// 	// printf("%s", line4);
// 	// printf("%s", line5);
// 	close(fd);
// 	free(line1);
// 	free(line2);
// }