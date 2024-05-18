/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:26:14 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/17 18:18:57 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <fcntl.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd > 0)
		write(fd, &c, 1);
}
/*
int	main (void)
{
	int fd = open("./../TEST_COM.text", O_WRONLY | O_CREAT);

	ft_putchar_fd('s',fd);
	close (fd);
} */
