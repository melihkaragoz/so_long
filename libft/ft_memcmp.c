/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:02:50 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:02:50 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			len;
	unsigned char	*i;
	unsigned char	*a;

	i = (unsigned char *)s1;
	a = (unsigned char *)s2;
	len = 0;
	while (len < n)
	{
		if ((i[len]) != (a[len]))
			return ((i[len]) - (a[len]));
		len++;
	}
	return (0);
}
