#include "libft.h"

t_list     *ft_lstend(t_list *lst)
{
    while (lst && lst->next)
        lst = lst->next;
    return (lst);
}