#include "validation.h"

#include "data.h"

int	cmp(t_data *a, t_data *b)
{
	return (a->val - b->val);
}

bool	is_valid_num(char *str1)
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

bool	has_duplicate(t_list *list)
{
	t_list	*sorted;
	t_list	*save;
	int		prev;
	bool	rtn;

	if (list == NULL || list->next == NULL)
		return (false);
	sorted = ft_lstndup(list, -1);
	ft_lst_sort(&sorted, cmp);
	prev = get_value(sorted);
	save = sorted;
	sorted = sorted->next;
	rtn = false;
	while (sorted && !rtn)
	{
		if (prev == get_value(sorted))
			rtn = true;
		prev = get_value(sorted);
		sorted = sorted->next;
	}
	ft_lstclear(&save, free);
	return (rtn);
}
