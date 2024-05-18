/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhobba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:44:43 by akhobba           #+#    #+#             */
/*   Updated: 2023/11/11 09:05:23 by akhobba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num != 0 && ((size * num) / num) != size)
		return (NULL);
	ptr = malloc(num * size);
	if (ptr)
	{
		ft_bzero(ptr, num * size);
		return (ptr);
	}
	return (NULL);
}
/*
int main ()
{
	int *arr = (int *)calloc(21443648,4);
	printf("%d",arr[0]);

}*/
