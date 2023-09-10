#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                t_list;

int ft_list_size(t_list *begin_list)
{
	int i = 0;
	t_list *ptr = begin_list;

	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

/*
int main(void)
{
	t_list *a = malloc(sizeof(t_list));
	t_list *b = malloc(sizeof(t_list));

	int c = 5;
	int d = 0;

	a->data = &c;
	b->data = &d;

	a->next = b;
	b->next = NULL;

	printf("size: %i\n", ft_list_size(a));
}
*/
