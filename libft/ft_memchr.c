/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:02:40 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:02:40 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*i;
	size_t			len;

	i = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		if (i[len] == (unsigned char)c)
			return (i + len);
		len++;
	}
	return (NULL);
}
