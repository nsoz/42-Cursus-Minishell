/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:25:05 by asenel            #+#    #+#             */
/*   Updated: 2023/07/09 14:42:17 by asenel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		a;
	char	ch;

	ch = (unsigned char)c;
	a = 0;
	while (str[a])
		a++;
	if (ch == '\0')
		return ((char *)&str[a]);
	a--;
	while (a >= 0 && str[a] != ch)
		a--;
	if (a >= 0 && str[a] == ch)
		return ((char *)&str[a]);
	return (NULL);
}
