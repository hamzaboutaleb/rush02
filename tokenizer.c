/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 09:53:36 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 14:46:07 by hboutale         ###   ########.fr       */
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

t_token	*parse_file(char *filename, t_token *res)
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
	line = get_line(fd);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (count_words(line, ":") < 2)
			{
				free(res);
				free(line);
				return (NULL);
			}
			if (!insert_token(res, k, line) || ft_strlen(res[k].key) == 0
				|| ft_strlen(res[k].value) == 0)
				return (free_tokens(res, k));
			k++;
		}
		free(line);
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
	return (1);
}

char	*search(t_token *tokens, char *s)
{
	int	i;

	i = 0;
	while (tokens[i].key != NULL)
	{
		if (ft_strcmp(tokens[i].key, s) == 0)
		{
			return (tokens[i].value);
		}
		i++;
	}
	return (NULL);
}

char	*searchn(t_token *tokens, char *s, int n)
{
	int	i;

	i = 0;
	while (tokens[i].key != NULL)
	{
		if (ft_strncmp(tokens[i].key, s, n) == 0)
		{
			return (tokens[i].value);
		}
		i++;
	}
	return (NULL);
}

char	*get_token_length(t_token *token, int n)
{
	int	i;

	i = 0;
	while (token[i].key)
	{
		if (ft_strlen(token[i].key) == n)
		{
			return (token[i].value);
		}
		i++;
	}
	return (NULL);
}

char	*get_tens(t_token *token, char *s)
{
	int	i;

	i = 0;
	while (token[i].key)
	{
		if (ft_strlen(token[i].key) == 2 && token[i].key[0] == s[0])
		{
			return (token[i].value);
		}
		i++;
	}
	return (NULL);
}

char	*get_unit(t_token *token, char *s)
{
	int	i;

	i = 0;
	while (token[i].key)
	{
		if (ft_strlen(token[i].key) == 1 && token[i].key[0] == s[0])
		{
			return (token[i].value);
		}
		i++;
	}
	return (NULL);
}
