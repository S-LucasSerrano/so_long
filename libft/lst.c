#include "libft.h"

/* Creates -with malloc- a new element of the list
with content = <con> and next = NULL */
t_list	*ft_lstnew(void *con)
{
	t_list	*output;

	output = (t_list *)malloc(sizeof(t_list));
	if (!output)
		return (NULL);
	output->content = con;
	output->next = NULL;
	return (output);
}

/* Adds <new> at the end of <lst> */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		(ft_lstlast(*lst))->next = new;
	else
		*lst = new;
}

/* Sets the element pointed by <new> as the 
first element of the list pointed by <lst> */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* Returs a pointer to the last element of <lst> */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* Returns the number of elements in <lst> */
int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
