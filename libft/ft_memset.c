/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:42:45 by asenel            #+#    #+#             */
/*   Updated: 2023/07/07 16:40:50 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	acar;
	char	*str1;

	str1 = str;
	acar = 0;
	while (acar < n)
	{
		str1[acar] = c;
		acar++;
	}
	return (str);
}
