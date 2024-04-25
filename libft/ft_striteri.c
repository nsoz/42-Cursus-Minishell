/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:12:43 by asenel            #+#    #+#             */
/*   Updated: 2023/07/10 19:54:51 by asenel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	c;
	int	length;

	length = ft_strlen(s);
	c = 0;
	if (!s)
		return ;
	while (c < length)
	{
		(*f)(c, &s[c]);
		c++;
	}
	s[c] = '\0';
}
