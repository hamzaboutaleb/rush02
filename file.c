/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:36:55 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 09:48:05 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*get_line(int fd)
{
	t_array *arr;
	int c;
	char *res;
	int bytes;

	arr = init_array(16);
	bytes = read(fd, &c, 1);
	while (bytes != 0 && c != '\n')
	{
		insert(arr, c);
		bytes = read(fd, &c, 1);
	}
	if (bytes == 0 && arr->size == 0)
	{
		free_array(arr);
		return (NULL);
	}

	insert(arr, '\0');
	res = arr->array;
	free(arr);
	return (res);
}