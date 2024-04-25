/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:14:39 by asenel            #+#    #+#             */
/*   Updated: 2023/07/09 14:40:16 by asenel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	c1;
	unsigned int	c2;

	c1 = 0;
	c2 = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !str)
		return (NULL);
	while (s1[c1] && c1 < ft_strlen(s1))
	{
		str[c1] = s1[c1];
		c1++;
	}
	while (s2[c2] && c2 < ft_strlen(s2))
	{
		str[c1 + c2] = s2[c2];
		c2++;
	}
	str[c1 + c2] = '\0';
	return (str);
}
