/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:35:57 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 09:48:17 by hboutale         ###   ########.fr       */
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
	int fd;
	char *line;

	if (!init_args(&args, ac, av) && !check_args(&args))
		return (1);
	printf("filen name %s\n", args.dict);
	fd = open(args.dict, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Error: Cannot Read file\n");
		return (1);
	}
	while ((line = get_line(fd)))
	{
		printf("%s\n", line);
	}
}