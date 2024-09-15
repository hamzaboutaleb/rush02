/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:36:48 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 09:43:15 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *s)
{
	int i;
	int len;

	len = ft_strlen(s);
	i = 0;
	if (len == 0 || (len == 1 && !is_digit(s[i])))
		return (0);
	if (s[i] == '-')
		return (0);
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (0);
		i++;
	}
	return (1);
}