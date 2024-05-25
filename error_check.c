/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 02:02:25 by muoz              #+#    #+#             */
/*   Updated: 2024/05/03 05:45:56 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_message(int error, char flag, char c)
{

	if (error == 1 && flag == 'q')
		printf("Not interpret unclosed quotes\n");
	if (flag == 'r' || flag == 'c')
	{
		if (c == '<' && error >= 3)
			printf("syntax error near unexpected token '%c%c%c'\n", c,c,c);
		else if (error == 1)
			printf("syntax error near unexpected token '%c'\n", c);
		else if (error >= 2)
			printf("syntax error near unexpected token '%c%c'\n", c,c);	
	}
	if (flag == 'l')
	{
		if (error == 3 && (c == '>' || c == '<'))
			printf("syntax error near unexpected token `newline'\n");
		else if (error == 2  && c == '|')
			printf("syntax error near unexpected token `%c'\n", c);
		else if (c == '|' && error == 4)
			printf("syntax error near unexpected token `%c%c'\n", c,c);
	}
	return (0);
}

int	ft_is_token(char *com)
{
	if (!com)
		return(0);
	if (com[0] == '|' || com[0] == '>' || com[0] == '<')
	{
			return (1);
	}
	return (0);
}

int	ft_quote_err(char *command_line)
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
				return (ft_error_message(1, 'q', 'q'));
		}
		i++;
	}
	return (1);
}

int	ft_repeat_err(char **all_of_com, char current, int *i, int *rflag)
{
	int	rep;

	rep = 0;
	while (all_of_com[*i] && all_of_com[*i][0] == current)
	{
		rep++;
		(*i)++;
		if (rep == 2)
			*rflag = 1;
	}
	if (rep > 2 && current != '|')
		return (ft_error_message((rep - 2), 'r', current));
	else if (rep > 1 && current == '|')
		return (ft_error_message((rep - 1), 'r', current));
	else 
		return (1);
}

int	ft_comb_cal(char **all_of_reb)
{
	int i = -1;
	char r;
	int rebel;

	rebel = 0;
	r = all_of_reb[0][0];
	while (all_of_reb[++i] && all_of_reb[i][0] == r)
		rebel++;
	return (rebel);
}

int	ft_comb_err(char **all_of_com, int tmp, int i)
{
	if (tmp != 0 && all_of_com[tmp - 1])
	{
		if ((ft_is_token(all_of_com[tmp - 1])) && all_of_com[tmp - 1] != all_of_com[tmp])
		{
			return (ft_error_message(ft_comb_cal((all_of_com + tmp + 1)), 'c', all_of_com[tmp][0]));
		}
	}
	if ((i != ft_dimensionlen(all_of_com) - 1) && all_of_com[i + 1])
	{
		if ((ft_is_token(all_of_com[i + 1])) && all_of_com[i + 1] != all_of_com[i])
		{
			return (ft_error_message(ft_comb_cal((all_of_com + i + 1)), 'c', all_of_com[i + 1][0]));
		}
	}
	return (1);
}

int	ft_dimensionlen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_loc_err(char current, int i, int len)
{
	int error;

	error = 2;
	if (current == '|')
	{
		if (i == 0 )
		{
			return (ft_error_message(error, 'l', '|'));
		}
	}
	if (current == '>' || current == '<')
	{
		if (i == (len - 1))
			return (ft_error_message(3, 'l', current));
	}
	return (1);
}
