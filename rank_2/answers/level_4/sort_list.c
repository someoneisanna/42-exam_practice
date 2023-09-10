#include <stdio.h>
#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

/*
int ascending(int a, int b)
{
	return (a <= b);
}
*/

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int tmp = 0;
	t_list *cur = lst;
	while(lst->next)
	{
		if(cmp(lst->data, lst->next->data) == 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = cur;
		}
		else
			lst = lst->next;
	}
	lst = cur;
	return (lst);
}


int main(void)
{
	t_list *a = (t_list *)malloc(sizeof(t_list));
	t_list *b = (t_list *)malloc(sizeof(t_list));

	a->data = 20;
	b->data = 5;

	a->next = b;
	b->next = NULL;

	t_list *ptr = a;

	while(ptr)
	{
		printf("%i\n", ptr->data);
		ptr = ptr->next;
	}
}
