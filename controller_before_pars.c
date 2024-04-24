/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_before_pars.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:12:32 by muoz              #+#    #+#             */
/*   Updated: 2024/04/24 19:46:07 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* int	ft_check_quote(char *command_line)
{
	int i;
	int single_quote_open = 0;
	int double_quote_open = 0;

	i = -1;
	while (command_line[++i] != '\0')
	{
		if (command_line[i] == '\'')
		{
			if (!single_quote_open)
				single_quote_open = 1;
			else
				single_quote_open = 0; // kapalı '
		}
		if (command_line[i] == '\"')
		{
			if (!double_quote_open)
				double_quote_open = 1;
			else
				double_quote_open = 0; // kapali "
		}
	}
	if (single_quote_open || double_quote_open)
	{
		ft_error_message(1);
		return 1; // kapanmamışşş
	}

	return 0; // Bir problem yok
}
*/

int ft_check_quote(char *command_line) {
    int i = 0;
    char current_quote;

    while (command_line[i] != '\0') {
        // Check if current character is a quote
        if (command_line[i] == '\'' || command_line[i] == '\"') {
            current_quote = command_line[i];  // Store the current quote type
            i++;
            // Look for the closing quote of the same type
            while (command_line[i] != '\0' && command_line[i] != current_quote)
                i++;
            
            // If end of string is reached without finding a closing quote
            if (command_line[i] == '\0') {
                ft_error_message(1);
                return 1;  // Return 1 indicating unclosed quote
            }
        }
        i++;  // Move to the next character
    }
    return 0;  // Return 0 if all quotes are properly closed
}

int ft_orientation_loc(char *command_line)
{
    int i;

	i = strlen(command_line) - 1;
    while (i >= 0 && command_line[i] == ' ')
        i--;
    if (i >= 0 && (command_line[i] == '<' || command_line[i] == '>'))
    {
        ft_error_message(2);
        return 1; // sonda redirection var
    }

    return 0; // sonda redirection yok
}


int ft_pipe_loc(char *command_line)
{
    int i;

	i = 0;
    while (command_line[i] == ' ')
        i++;
    if (command_line[i] == '|')
    {
        ft_error_message(3);
        return 1; // başta pipe var
    }
    return 0; // başta pipe yok
}