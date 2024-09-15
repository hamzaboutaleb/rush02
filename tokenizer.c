/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:53:36 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 12:08:07 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	skip_space(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

int	skip_digit(char *line, int i)
{
	while (line[i] && is_digit(line[i]))
		i++;
	return (i);
}

int	skip_end(char *line, int i)
{
	while (line[i])
		i++;
	return (i);
}

void	*free_tokens(t_token *tokens, int end)
{
	int	i;

	i = 0;
	while (i <= end)
	{
		free(tokens[i].key);
		free(tokens[i].value);
		i++;
	}
	free(tokens);
	return (NULL);
}

t_token	*parse_file(char *filename, int number_line, t_token *res)
{
	char	*line;
	int		k;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: Cannot Read file\n");
		return (NULL);
	}
	k = 0;
	number_line++;
	line = get_line(fd);
	while (line)
	{
		printf("%d\n", k);
		if (count_words(line, ":") < 2)
		{
			free(res);
			free(line);
			return (NULL);
		}
		if (!is_empty_line(line))
		{
			if (!insert_token(res, k, line))
				return (free_tokens(res, k));
		}
		free(line);
		k++;
		line = get_line(fd);
	}
	res[k].key = NULL;
	res[k].value = NULL;
	return (res);
}

int	insert_token(t_token *tokens, int idx, char *line)
{
	int	start;
	int	end;
	int	i;
	int	error;

	error = 0;
	i = 0;
	i = skip_space(line, i);
	start = i;
	i = skip_digit(line, i);
	end = i;
	if (start == end)
		return (0);
	tokens[idx].key = str_dup(line, start, end);
	i = skip_space(line, i);
	if (line[i] && line[i] != ':')
		return (0);
	else
		i++;
	i = skip_space(line, i);
	start = i;
	i = skip_end(line, i);
	end = i;
	tokens[idx].value = str_dup(line, start, end);
	printf("key: %s value %s\n", tokens[idx].key, tokens[idx].value);
	return (1);
}
