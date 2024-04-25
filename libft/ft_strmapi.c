/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:48:51 by asenel            #+#    #+#             */
/*   Updated: 2023/07/09 18:04:34 by asenel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	c;
	unsigned int	length;
	char			*str;

	c = 0;
	length = (unsigned int)ft_strlen(s);
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	while (c < length)
	{
		str[c] = (*f)(c, s[c]);
		c++;
	}
	str[c] = '\0';
	return (str);
}
