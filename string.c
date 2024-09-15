/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:46:45 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 10:58:47 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
	}
	return (1);
}

char	*str_dup(char *line, int start, int end)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = end - start;
	res = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		res[i] = line[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	string_has(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int res;
	int i;

	i = 0;
	res = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		while (str[i] && string_has(charset, str[i]))
			i++;
		if (str[i])
			res++;
		while (str[i] && !string_has(charset, str[i]))
			i++;
	}
	return (res);
}