/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:43:59 by muoz              #+#    #+#             */
/*   Updated: 2024/04/25 19:30:14 by muoz             ###   ########.fr       */
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
void	ft_error_message(int flag);
int		ft_orientation_loc(char *command_line);
int		ft_pipe_loc(char *command_line);
void	ft_put_input(t_data *data, char *commandline);
void	parse_command(char *command_line);
void	ft_pass_quote(char *command_line, int *i);

#endif