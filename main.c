/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:35:57 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 14:59:50 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	init_args(t_args *args, int ac, char **av)
{
	args->dict = "numbers.dict";
	if (ac == 0 || ac > 3)
	{
		ft_putstr("USAGE: ./rush-02 [DICT] [NUMBER] | [NUMBER]\n");
		return (0);
	}
	if (ac == 2)
		args->number = av[1];
	else
	{
		args->dict = av[1];
		args->number = av[2];
	}
	return (1);
}

char	*to_number(char *s)
{
	int		i;
	int		len;
	t_array	*num;
	char	*res;

	num = init_array(10);
	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	while (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i] && is_digit(s[i]))
	{
		insert(num, s[i]);
		i++;
	}
	insert(num, '\0');
	res = num->array;
	free(num);
	return (res);
}

int	check_args(t_args *args)
{
	if (!is_number(args->number))
	{
		ft_putstr("Error\n");
		return (0);
	}
	args->number = to_number(args->number);
	printf("%s\n", args->number);
	return (1);
}

char	*int_to_eng(char *s, t_token *tokens)
{
	int		nlen;
	t_array	*num;
	int		i;
	char	*found;

	num = init_array(100);
	nlen = ft_strlen(s);
	i = 0;
	found = search(tokens, s);
	if (found != NULL)
	{
		insert_str(num, found);
		insert_str(num, "\0");
		return (num->array);
	}
	while (i < nlen)
	{
		if (nlen - i == 2)
		{
			if (s[i + 1] == '0')
			{
				found = searchn(tokens, &s[i], 2);
				if (found)
					insert_str(num, found);
				insert_str(num, "\0");
				return (num->array);
			}
			else
			{
				if (s[i] == '1')
				{
					found = searchn(tokens, &s[i], 2);
					insert_str(num, found);
				}
				else
				{
					insert_str(num, get_tens(tokens, s + i));
					i++;
					insert_str(num, " ");
					insert_str(num, get_unit(tokens, s + i));
				}
				insert_str(num, "\0");
				return (num->array);
			}
		}
		found = searchn(tokens, &s[i], 1);
		if (found)
			insert_str(num, found);
		found = get_token_length(tokens, nlen - i);
		if (found)
		{
			insert_str(num, " ");
			insert_str(num, found);
		}
		insert_str(num, " ");
		i++;
	}
	insert(num, '\0');
	return (num->array);
}

int	main(int ac, char **av)
{
	t_args args;
	int number_lines;
	t_token *tokens;

	if (init_args(&args, ac, av) == 0 || check_args(&args) == 0)
		return (1);

	number_lines = count_lines(args.dict);
	tokens = (t_token *)malloc(sizeof(t_token) * (number_lines + 1));
	tokens = parse_file(args.dict, tokens);
	if (tokens == NULL)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	ft_putstr(int_to_eng(args.number, tokens));
	/*for (int i = 0; tokens[i].key != NULL; i++)
	{
		ft_putstr("key:");
		ft_putstr(tokens[i].key);
		ft_putstr(" value:");
		ft_putstr(tokens[i].value);
		ft_putstr("\n");
	}*/
}