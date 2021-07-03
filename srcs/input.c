#include "push_swap.h"

#include <stdbool.h>
#include "libft.h"
#include "error.h"

bool	is_valid(char *str1)
{
	int		num;
	char	*str2;

	num = ft_atoi(str1);
	str2 = ft_itoa(num);
	if (str2 == NULL)
		return (false);
	num = ft_strcmp(str1, str2);
	free(str2);
	if (num)
		return (false);
	return (true);
}

t_list	*make_data(int argc, char *argv[])
{
	t_list	*list;
	t_list	*append;
	int		*content;

	list = NULL;
	while (--argc)
	{
		content = (int *)malloc(sizeof(int));
		if (content == NULL || !is_valid(argv[argc]))
			error();
		*content = ft_atoi(argv[argc]);
		append = ft_lstnew(content);
		if (append == NULL)
			error();
		ft_lstadd_front(&list, append);
	}
	return (list);
}
