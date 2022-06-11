/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:00:51 by psimarro          #+#    #+#             */
/*   Updated: 2021/11/12 18:00:54 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char a, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	begin;
	size_t	end;

	if (!s1)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_in_set(s1[begin], set))
		begin++;
	while (end > begin && ft_in_set(s1[end - 1], set))
		end--;
	dst = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (begin < end)
		dst[i++] = s1[begin++];
	dst[i] = 0;
	return (dst);
}
