/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:29:27 by muoz              #+#    #+#             */
/*   Updated: 2024/04/25 20:15:19 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_message(int flag)
{
	if (flag == 1)
		printf("Not interpret unclosed quotes\n");
	if (flag == 2)
		printf("syntax error near unexpected token `newline'\n");
	if (flag == 3)
		printf("syntax error near unexpected token `|'\n");
}

void	ft_pass_quote(char *command_line, int *i)
{
	int	quote_flag;

	quote_flag = 0;
	if (command_line[*i] == '\"')
		quote_flag = 1;
	else if (command_line[*i] == '\'')
		quote_flag = 2;
	while (command_line[++(*i)])
	{
		if ((quote_flag == 1 && command_line[*i] == '\"')
			|| (quote_flag == 2 && command_line[*i] == '\''))
		{
			(*i)++;
			break ;
		}
	}
}

int	ft_layer_cal(char *command_line, int i, int ret)
{
	while (command_line[i])
	{
		while (command_line[i] == ' ')
			i++;
		if (command_line[i] == '\0')
			break ;
		ret++;
		if (command_line[i] == '|' || command_line[i] == '>'
			|| command_line[i] == '<')
		{
			i++;
			continue ;
		}
		while (command_line[i] && command_line[i] != ' '
			&& command_line[i] != '|' && command_line[i] != '>'
			&& command_line[i] != '<')
		{
			if (command_line[i] == '\"' || command_line[i] == '\'')
				ft_pass_quote(command_line, &i);
			else
				i++;
		}
	}
	return (ret);
}

int	ft_pre_pars(char *command_line)
{
	int	error;

	error = 0;
	error += ft_pipe_loc(command_line);
	if (error)
		return (error);
	error += ft_check_quote(command_line);
	if (error)
		return (error);
	error += ft_orientation_loc(command_line);
	return (error);
}

void	parse_command(char *command_line)
{
	t_data	*data;
	int		error;

	error = ft_pre_pars(command_line);
	if (!error)
	{
		data = malloc(sizeof(t_data));
		data->layer = ft_layer_cal(command_line, 0, 0);
		data->command = malloc((data->layer + 1) * sizeof(char *));
		ft_put_input(data, command_line);
	}
}
