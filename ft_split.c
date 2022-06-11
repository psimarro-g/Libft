/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:32:56 by psimarro          #+#    #+#             */
/*   Updated: 2021/11/12 18:33:01 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sep_in_set(char c, char const *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static void	*ft_free_all_alloc(char **spl, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
	return (NULL);
}

static void	*ft_fill(char **spl, char const *s, t_split *st, int i)
{
	st->length = (i - st->start);
	spl[st->pos] = ft_substr(s, st->start, st->length);
	if (!spl[st->pos])
		return (ft_free_all_alloc(spl, st->pos));
	st->pos++;
	return (spl);
}

static void	*ft_split_char(char **spl, char const *s, char c)
{
	size_t	i;
	t_split	st;

	i = 0;
	st.pos = 0;
	while (s[i] && s[i] == c)
		i++;
	st.start = i;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i > st.start && !ft_fill(spl, s, &st, i))
				return (NULL);
			while (s[i] == c)
				i++;
			st.start = i--;
		}
		i++;
	}
	st.length = (i - st.start);
	if (i > st.start && i > 0 && !ft_fill(spl, s, &st, i))
		return (NULL);
	spl[st.pos] = NULL;
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;

	if (!s)
		return (NULL);
	spl = (char **)malloc(sizeof(char *) * (sep_in_set(c, s) + 1));
	if (!spl)
		return (NULL);
	if (!ft_split_char(spl, s, c))
		return (NULL);
	return (spl);
}
