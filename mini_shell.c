/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:29:02 by muoz              #+#    #+#             */
/*   Updated: 2024/04/25 16:32:05 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*command_line;

	while (1)
	{
		command_line = readline("my shell: ");
		if (command_line == NULL)
		{
			printf("An error occurred.\n");
			continue ;
		}
		if (strcmp(command_line, "exit") == 0)
			break ;
		parse_command(command_line);
		add_history(command_line);
	}
	return (0);
}
