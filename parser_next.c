/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:36:32 by muoz              #+#    #+#             */
/*   Updated: 2024/04/26 01:02:30 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_rep_cal(t_data *data, char *reb, int repeat)
{
	int	i;
	int	err;

	err = 0;
	i = -1;
	while (data->command[++i] != NULL)
	{
		if (!ft_strncmp(data->command[i], reb, ft_strlen(data->command[i])))
			err++;
		else
		{
			if (err >= repeat)
				break ;
			err = 0;
		}
	}
	if (err == repeat)
		return (1);
	else if (err == (repeat + 1))
		return (2);
	else if (err > (repeat + 1))
		return (3);
	return (0);
}

int	ft_check_flag(int error, char c)
{
	if (error == 1)
		printf("syntax error near unexpected token `%c'\n", c);
	else if (!(error == 3 && c == '<'))
		printf("syntax error near unexpected token `%c%c'\n", c, c);
	else
		printf("syntax error near unexpected token `%c%c%c'\n", c, c, c);
	return (error);
}

int	ft_after_pars(t_data *data)
{
	int	error;

	error = 0;
	error += ft_rep_cal(data, "|", 3);
	if (error)
		return (ft_check_flag(error, '|'));
	error += ft_rep_cal(data, ">", 3);
	if (error)
		return (ft_check_flag(error, '>'));
	error += ft_rep_cal(data, "<", 4);
	if (error)
		return (ft_check_flag(error, '<'));
	return (error);
}

int	ft_is_inc(char c)
{
	if (c && c != ' ' && c != '|' && c != '>' && c != '<')
		return (1);
	else
		return (0);
}

char	*ft_parser(char *command_line, int *index, int sub_index, int flag)
{
	while (command_line[*index])
	{
		while (command_line[*index] == ' ')
		{
			(*index)++;
			sub_index++;
		}
		if (command_line[*index] == '|' || command_line[*index] == '>'
			|| command_line[*index] == '<')
		{
			(*index)++;
			break ;
		}
		while (ft_is_inc(command_line[*index]))
		{
			flag = 1;
			if (command_line[*index] == '\"' || command_line[*index] == '\'')
				ft_pass_quote(command_line, index);
			else
				(*index)++;
		}
		if (flag)
			break ;
	}
	return (ft_substr(command_line, sub_index, (*index - sub_index)));
}

void	ft_put_input(t_data *data, char *command_line)
{
	int	i;
	int	com_index;
	int	sub_index;

	com_index = 0;
	i = -1;
	while (++i < data->layer)
	{
		sub_index = com_index;
		data->command[i] = ft_parser(command_line, &com_index, sub_index, 0);
	}
	data->command[i] = NULL;
	ft_after_pars(data);
}
