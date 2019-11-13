/* ------------------------- TEST PHASE ---------------------------- */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*content))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	put_list(t_list *list)
{
    if (list == NULL)
        return ;

    t_list *actuel;
	
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
}