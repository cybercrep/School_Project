/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 23:23:07 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 23:23:07 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*begin_lst;
	t_list		*new_lst;

	begin_lst = (*f)(lst);
	new_lst = begin_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = (*f)(lst);
		lst = lst->next;
		new_lst = new_lst->next;
	}
	new_lst->next = NULL;
	return (begin_lst);
}
