/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:14:27 by psimarro          #+#    #+#             */
/*   Updated: 2021/11/13 20:14:33 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_a;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		lst_a = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_a;
	}
}
