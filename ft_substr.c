/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:04:30 by psimarro          #+#    #+#             */
/*   Updated: 2021/11/12 17:04:32 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			dst[j++] = s[i];
		i++;
	}
	dst[j] = 0;
	return (dst);
}
