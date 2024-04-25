/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:36:32 by muoz              #+#    #+#             */
/*   Updated: 2024/04/25 20:13:30 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	i = 0;
	while (data->command[i] != NULL)
	{
		printf("%s\n", data->command[i]);
		i++;
	}
	printf("%d\n", i);
}
