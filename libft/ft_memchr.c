/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:18:03 by asenel            #+#    #+#             */
/*   Updated: 2023/07/15 11:57:35 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			a;
	unsigned char	*str1;

	str1 = (unsigned char *)str;
	a = 0;
	while (a < n)
	{
		if (str1[a] == (unsigned char)c)
			return (&str1[a]);
		a++;
	}
	return (NULL);
}
