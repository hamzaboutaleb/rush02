/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:42:19 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 09:49:56 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
	char	*number;
	char	*dict;
}			t_args;

typedef struct {
	char *value;
} token;

// STRING
void		ft_putstr(char *s);
int			ft_strlen(char *s);
// FILE
char		*get_line(int fd);
// NUMBERS
int			is_number(char *s);

// ARRAY
typedef struct
{
	char	*array;
	int		size;
	int		cap;
}			t_array;
t_array		*init_array(int cap);
void		insert(t_array *arr, char c);
char		get(t_array *arr, int i);
void		free_array(t_array *arr);
