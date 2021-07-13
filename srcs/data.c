#include "data.h"

#include <stdbool.h>
#include "libft.h"
#include "error.h"
#include "validation.h"

t_list	*make_data(int argc, char *argv[])
{
	t_list	*list;
	t_list	*append;
	t_data	*data;

	list = NULL;
	while (--argc)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (data == NULL || !is_valid_num(argv[argc]))
			error();
		data->val = ft_atoi(argv[argc]);
		data->is_start = false;
		append = ft_lstnew(data);
		if (append == NULL)
			error();
		ft_lstadd_front(&list, append);
	}
	if (has_duplicate(list))
		error();
	return (list);
}

int	get_value(t_list *list)
{
	return (((t_data *)list->content)->val);
}

bool	is_start(t_list *list)
{
	return (((t_data *)list->content)->is_start);
}
