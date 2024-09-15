/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:36:48 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 13:50:42 by hboutale         ###   ########.fr       */
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
	int sign;

	sign = 1;
	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	while (s[i] && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign == -1)
		return (0);

	if (!is_digit(s[i]))
	{
		return (0);
	}

	return (1);
}