#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
} t_list;

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *ptr;

	ptr = begin_list;
	while(ptr)
	{
		(*f)(ptr->data);
		ptr = ptr->next;
	}
}

/*
void ft_print(void *data)
{
	printf("%s\n", (char *)data);
}

int main(void)
{
	t_list *a = malloc(sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));

	a->data = "1";
	b->data = "2";

	a->next = b;
	b->next = NULL;

	ft_list_foreach(a, &ft_print);
}
*/
