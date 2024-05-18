/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:52:16 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/11 09:57:01 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*string;
	const unsigned char	*string2;

	string = (unsigned char *)dest;
	string2 = (unsigned char *)src;
	if (!string && !string2)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			string[n - 1] = string2[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
