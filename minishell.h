/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:43:59 by muoz              #+#    #+#             */
/*   Updated: 2024/04/21 03:23:10 by muoz             ###   ########.fr       */
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

void	ft_check_quote(char *command_line);
void	ft_error_message(int flag);
void	ft_orientation_loc(char *command_line);
void	ft_pipe_loc(char *command_line);

#endif