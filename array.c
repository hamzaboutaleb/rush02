/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:12:45 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 09:30:53 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_array	*init_array(int cap)
{
	t_array	*arr;

	arr = (t_array *)malloc(sizeof(t_array));
	if (arr == NULL)
		return (NULL);
	arr->array = (char *)malloc(sizeof(char) * cap);
	if (arr->array == NULL)
	{
		free(arr);
		return (NULL);
	}
	arr->size = 0;
	arr->cap = cap;
	return (arr);
}

void	resize(t_array *arr)
{
	int		new_cap;
	char	*new_array;
	int		i;

	i = 0;
	new_cap = arr->cap * 2;
	new_array = (char *)malloc(sizeof(char) * new_cap);
	while (i < arr->cap)
	{
		new_array[i] = arr->array[i];
		i++;
	}
	free(arr->array);
	arr->array = new_array;
	arr->cap = new_cap;
}

void	insert(t_array *arr, char c)
{
	if (arr->size == arr->cap)
		resize(arr);
	arr->array[arr->size++] = c;
}

char	get(t_array *arr, int i)
{
	if (i < 0 || i >= arr->size)
		return (-1);
	return (arr->array[i]);
}

void	free_array(t_array *arr)
{
	free(arr->array);
	free(arr);
}