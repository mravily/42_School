void	put_list(t_list *list)
{
    if (list == NULL)
        return ;

    t_list *actuel;
	
	actuel = list;
    while (actuel != NULL)
    {
        printf("%d -> ", (int)actuel->content);
        actuel = actuel->next;
    }
    printf("NULL\n");
}

int		main(void)
{
	t_list *list;
	
	list = ft_lstnew(5);
	put_list(list);
}