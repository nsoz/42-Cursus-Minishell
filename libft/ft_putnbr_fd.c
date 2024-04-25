/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenel <asenel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:56:58 by asenel            #+#    #+#             */
/*   Updated: 2023/07/09 18:09:01 by asenel           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	c;

	c = n;
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c *= -1;
	}
	if (c > 9)
	{
		ft_putnbr_fd(c / 10, fd);
		ft_putchar_fd((c % 10) + '0', fd);
	}
	else
		ft_putchar_fd(c + '0', fd);
}
