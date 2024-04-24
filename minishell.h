/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:43:59 by muoz              #+#    #+#             */
/*   Updated: 2024/04/24 15:48:17 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_data
{
	char		**command;
	int			layer;
}	t_data;

#define MAX_CMD_LEN 1024
#define MAX_NUM_TOKENS 64

int		ft_check_quote(char *command_line);
void	ft_error_message(int flag);
int		ft_orientation_loc(char *command_line);
int		ft_pipe_loc(char *command_line);
void ft_put_input(char **input);


#endif