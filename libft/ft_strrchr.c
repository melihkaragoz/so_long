/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:04:43 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:04:43 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	i;
	size_t			len;

	i = c;
	len = ft_strlen(s);
	if (i == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		if (s[len - 1] == i)
			return ((char *)&s[len - 1]);
		len--;
	}
	return (NULL);
}
