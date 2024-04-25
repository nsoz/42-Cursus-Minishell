/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_before_pars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:12:32 by muoz              #+#    #+#             */
/*   Updated: 2024/04/25 16:33:04 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_quote(char *command_line)
{
	int		i;
	char	current_quote;

	i = 0;
	while (command_line[i] != '\0')
	{
		if (command_line[i] == '\'' || command_line[i] == '\"')
		{
			current_quote = command_line[i];
			i++;
			while (command_line[i] != '\0' && command_line[i] != current_quote)
				i++;
			if (command_line[i] == '\0')
			{
				ft_error_message(1);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_orientation_loc(char *command_line)
{
	int	i;

	i = strlen(command_line) - 1;
	while (i >= 0 && command_line[i] == ' ')
		i--;
	if (i >= 0 && (command_line[i] == '<' || command_line[i] == '>'))
	{
		ft_error_message(2);
		return (1);
	}
	return (0);
}

int	ft_pipe_loc(char *command_line)
{
	int	i;

	i = 0;
	while (command_line[i] == ' ')
		i++;
	if (command_line[i] == '|')
	{
		ft_error_message(3);
		return (1);
	}
	return (0);
}
