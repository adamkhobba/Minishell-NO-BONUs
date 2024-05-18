/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:41:36 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/17 18:17:40 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	if (fd > 0)
	{
		nbr = n;
		if (nbr < 0)
		{
			nbr = nbr * (-1);
			ft_putchar_fd('-', fd);
		}
		if (nbr > 9)
		{
			ft_putnbr_fd(nbr / 10, fd);
			ft_putnbr_fd(nbr % 10, fd);
		}
		else
			ft_putchar_fd(nbr + 48, fd);
	}
}
/*
int	main (void)
{
	int fd = open("./../TEST_COM.text", O_WRONLY | O_CREAT);

	ft_putchar_fd('s',fd);
	close (fd);
} */
