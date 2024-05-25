/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:43:59 by muoz              #+#    #+#             */
/*   Updated: 2024/05/03 05:48:04 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_data
{
	char		**command;
	int			layer;
}	t_data;

# define MAX_CMD_LEN 1024
# define MAX_NUM_TOKENS 64

int		ft_check_quote(char *command_line);
int		ft_error_message(int error, char flag, char c);
int		ft_orientation_loc(char *command_line);
int		ft_pipe_loc(char *command_line);
void	ft_put_input(t_data *data, char *commandline);
void	parse_command(char *command_line);
void	ft_pass_quote(char *command_line, int *i);
int		ft_quote_err(char *command_line);
int		ft_is_token(char *com);
int		ft_repeat_err(char **all_of_com, char current, int *i, int *rflag);
int	ft_comb_err(char **all_of_com, int tmp, int i);
int		ft_dimensionlen(char **str);
int		ft_loc_err(char current, int i, int len);

#endif