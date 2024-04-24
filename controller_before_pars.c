/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_before_pars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:12:32 by muoz              #+#    #+#             */
/*   Updated: 2024/04/21 03:34:58 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_quote(char *command_line) // tırnak açılıp kapandı mı
{
	int	i;

	i = -1;
	while (command_line[++i] != '\0')
	{
		if (command_line[i] == '\'')
		{
			while (command_line[++i] != '\0')
				if (command_line[i] == '\'')
					break ;
			if (command_line[i] == '\0')
				ft_error_message(1);
		}
		if (command_line[i] == '\"')
		{
			while (command_line[++i] != '\0')
				if (command_line[i] == '\"')
					break ;
			if (command_line[i] == '\0')
				ft_error_message(1);
		}
	}
}

void	ft_orientation_loc(char *command_line) // redirection en sonda olup olamdığını kontrol eder
{
	int	i;

	i = strlen(command_line);
	while (command_line[--i])
	{
		while (command_line[i] == ' ')
			i--;
		if (command_line[i] == '<' || command_line[i] == '>')
		{
			ft_error_message(2);
			break ;
		}
		else
			break ;
	}
}

void	ft_pipe_loc(char *command_line) // pipe ın en başta olup olamdığını kontrol eder
{
	int	i;

	i = -1;
	while (command_line[++i])
	{
		if (i == 0 && command_line[i] == ' ')
			while (command_line[i] && command_line[i] == ' ') //varsa boşlukları atlar
				i++;
		if (command_line[i] && command_line[i] == '|')
			ft_error_message(3);
	}
}