/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:04:47 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/03/20 22:04:47 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		last;

	start = 0;
	last = ft_strlen(s1) -1;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[last]))
		last--;
	return (ft_substr(s1, start, last - start + 1));
}

/* int	main()
{
	char tab1[30] = "abcdba";
	char tab2[30] = "acb";

	printf("%s", ft_strtrim(tab1,tab2));
}  */
