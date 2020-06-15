#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*point;

	if (!lst || !(point = ft_lstnew(NULL, 0)))
		return (NULL);
	point = f(lst);
	begin = point;
	while (lst->next)
	{
		lst = lst->next;
		point->next = f(lst);
		point = point->next;
	}
	return (begin);
}
