/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:14:54 by asenel            #+#    #+#             */
/*   Updated: 2023/07/15 11:57:13 by asenel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*buffer;

	buffer = (void *)malloc(size * nitems);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, size * nitems);
	return (buffer);
}
