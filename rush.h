/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:42:19 by hboutale          #+#    #+#             */
/*   Updated: 2024/09/15 14:25:02 by hboutale         ###   ########.fr       */
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

typedef struct
{
	char	*key;
	char	*value;
}			t_token;

// STRING 0
void		ft_putstr(char *s);
int			ft_strlen(char *s);
int			is_empty_line(char *line);
char		*str_dup(char *line, int start, int end);
int			count_words(char *str, char *charset);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
// FILE 0
char		*get_line(int fd);

int			count_lines(char *filename);
// NUMBERS 0
int			is_number(char *s);
int			is_digit(char c);
// ARRAY 0
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
void		insert_str(t_array *arr, char *s);
// TOKEN 0
t_token		*parse_file(char *filename, t_token *res);
int			insert_token(t_token *tokens, int idx, char *line);
char		*search(t_token *tokens, char *s);
char		*searchn(t_token *tokens, char *s, int n);
char		*get_token_length(t_token *token, int n);
char		*get_tens(t_token *token, char *s);
char		*get_unit(t_token *token, char *s);