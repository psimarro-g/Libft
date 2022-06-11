/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:45:37 by psimarro          #+#    #+#             */
/*   Updated: 2021/11/13 17:45:39 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	char			*dst;

	if (!f || !s)
		return (NULL);
	size = 0;
	dst = ft_strdup(s);
	if (!dst)
		return (NULL);
	while (s[size])
	{
		dst[size] = (*f)(size, dst[size]);
		size++;
	}
	return (dst);
}
