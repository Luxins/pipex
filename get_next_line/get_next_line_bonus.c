/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljahn <ljahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:51:21 by ljahn             #+#    #+#             */
/*   Updated: 2022/05/07 07:55:03 by ljahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char	*cumulative[10240];
	char		*line;

	if (fd < 0 || fd > 10240)
		return (NULL);
	cumulative[fd] = reader(fd, cumulative[fd]);
	if (!cumulative[fd])
	{
		return (NULL);
	}
	if (cumulative[fd][0] == 0)
	{
		free(cumulative[fd]);
		return (NULL);
	}
	line = cutter(cumulative[fd]);
	cumulative[fd] = updater(cumulative[fd]);
	return (line);
}

// int	main(void)
// {
// // 	int		fd;
// // 	char	*line1;
// // 	char	*line2;
// // 	// char	*line3;
// // 	// char	*line4;
// // 	// char	*line5;

// // 	fd = open("bacon", O_RDWR);
// // 	line1 = get_next_line(fd);
// // 	line2 = get_next_line(fd);
// // 	// line3 = get_next_line(fd);
// // 	// line4 = get_next_line(fd);
// // 	// line5 = get_next_line(fd);
// // 	printf("%s", line1);
// // 	if (line2 == NULL)
// // 		printf("ACTUALLY A NULL.");
// // 	// printf("%s", line3);
// // 	// printf("%s", line4);
// // 	// printf("%s", line5);
// // 	close(fd);
// // 	free(line1);
// // 	free(line2);
// }