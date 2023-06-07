/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:54:29 by ale-boud          #+#    #+#             */
/*   Updated: 2023/04/13 18:07:05 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	l = ft_lstnew(f(lst->content));
	if (l == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		ft_lstadd_back(&l, new);
		lst = lst->next;
	}
	return (l);
}
