/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:35:57 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 12:08:24 by hboutale         ###   ########.fr       */
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

int	check_args(t_args *args)
{
	if (!is_number(args->dict))
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_args args;
	int number_lines;
	t_token *tokens;

	if (!init_args(&args, ac, av) && !check_args(&args))
		return (1);

	number_lines = count_lines(args.dict);
	tokens = (t_token *)malloc(sizeof(t_token) * (number_lines + 1));
	tokens = parse_file(args.dict, number_lines, tokens);
	if (tokens == NULL)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	for (int i = 0; tokens[i].key != NULL; i++)
	{
		printf("kye: %s value %s\n", tokens[i].key, tokens[i].value);
	}
}