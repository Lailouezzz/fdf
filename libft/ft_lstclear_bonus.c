/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:38:38 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 17:51:44 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;
	t_list	*to_free;

	l = *lst;
	while (l != NULL)
	{
		to_free = l;
		l = l->next;
		ft_lstdelone(to_free, del);
	}
	*lst = NULL;
}
