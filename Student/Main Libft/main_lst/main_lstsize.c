/* ------------------------- TEST PHASE ---------------------------- */

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

int		main(void)
{
	/* ----------------- 1st TEST ------------------- *\
	t_list **alst;
	t_list *first;
	t_list *secnd;

	if (!(alst = (t_list **)malloc(sizeof(t_list *) * 3)))
		return (NULL);
	first = ft_lstnew(5);
	alst[0] = first;
	secnd = ft_lstnew(6);
	ft_lstadd_front(alst, secnd);
	put_list(secnd);
	printf("lst_size = %d", ft_lstsize(secnd));
	\* --------------------------------------------- */

	/* ---------------- 2nd TEST ------------------- */
	t_list *l;
	int actual;
	int expected;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	expected = 3;
	actual = ft_lstsize(l);
	if (actual == expected)
		printf("TEST_SUCCESS\n");
	else
		printf("TEST_FAILED\n");
	printf("lst_size = %d", ft_lstsize(l));
}
