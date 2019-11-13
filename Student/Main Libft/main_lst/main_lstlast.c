

#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*content))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	put_list(t_list *list)
{
	t_list *actuel;

	if (list == NULL)
		return ;
	actuel = list;
	while (actuel != NULL)
	{
		printf("%d -> ", actuel->content);
		actuel = actuel->next;
	}
	printf("NULL\n");
}
void	put_link(t_list *list)
{
	t_list *actuel;

	if (list == NULL)
		return ;
	actuel = list;
		printf("%d -> ", actuel->content);
	printf("NULL\n");
}

int		main(void)
{
	t_list **alst;
	t_list *first;
	t_list *secnd;
	t_list *last;

	if (!(alst = (t_list **)malloc(sizeof(t_list *) * 3)))
		return (NULL);
	first = ft_lstnew(5);
	alst[0] = first;
	secnd = ft_lstnew(6);
	ft_lstadd_front(alst, secnd);
	put_list(secnd);
	last = ft_lstlast(secnd);
	put_link(last);
}
