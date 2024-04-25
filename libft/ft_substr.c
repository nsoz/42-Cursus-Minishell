/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:33:11 by asenel            #+#    #+#             */
/*   Updated: 2023/07/15 08:33:37 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	c;
	unsigned int	s_len;
	char			*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	if (len == 0)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	c = 0;
	while (c < len)
	{
		str[c] = s[c + start];
		c++;
	}
	str[c] = '\0';
	return (str);
}
