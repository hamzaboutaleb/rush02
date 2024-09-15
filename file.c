/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:36:55 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 11:59:58 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*get_line(int fd)
{
	t_array	*arr;
	int		c;
	char	*res;
	int		bytes;

	arr = init_array(16);
	bytes = read(fd, &c, 1);
	while (bytes && c != '\n')
	{
		insert(arr, c);
		bytes = read(fd, &c, 1);
	}
	if (arr->size == 0)
	{
		free_array(arr);
		return (NULL);
	}
	insert(arr, '\0');
	res = arr->array;
	free(arr);
	return (res);
}

int	count_lines(char *filename)
{
	int fd;
	int count;
	char *line;

	count = 0;
	fd = open(filename, O_RDONLY);
	line = get_line(fd);
	while (line)
	{
		
		if (!is_empty_line(line))
			count++;
		free(line);
		line = get_line(fd);
	}
	close(fd);
	return (count);
}