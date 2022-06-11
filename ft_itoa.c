/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:57:25 by psimarro          #+#    #+#             */
/*   Updated: 2021/11/12 20:57:26 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *dst)
{
	size_t	len;
	size_t	i;
	char	aux;

	len = ft_strlen(dst);
	i = 0;
	while (i < len / 2)
	{
		aux = dst[i];
		dst[i] = dst[len - i - 1];
		dst[len - i - 1] = aux;
		i++;
	}
}

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

static int	ft_get_size(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		is_neg;
	size_t	len;

	is_neg = (n < 0);
	dst = ft_calloc(ft_get_size(n) + is_neg + 1 + (n == 0), sizeof(char));
	if (!dst)
		return (NULL);
	if (n == 0)
		dst[0] = '0';
	len = 0;
	while (n != 0)
	{
		dst[len++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		dst[len] = '-';
	ft_strrev(dst);
	return (dst);
}
