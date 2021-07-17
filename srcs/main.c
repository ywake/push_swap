#include "push_swap.h"

#include "libft.h"
#include "data.h"
#include "stack.h"
#include "logging.h"
#include "debug.h"
#include "error.h"

void	print(void *str)
{
	ft_putendl_fd((char *)str, 1);
}

void	init_stacks(t_stack *stack, char *name, t_list *list, int len)
{
	stack->name = name;
	stack->top = list;
	stack->len = len;
}

int	check_sorted(t_stack *sta)
{
	t_list	*cur;

	cur = sta->top;
	while (cur && cur->next)
	{
		if (get_value(cur) > get_value(cur->next))
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*cmd;
	t_stack	sta;
	t_stack	stb;

	cmd = NULL;
	if (argc == 1)
		error();
	init_stacks(&sta, "a", make_data(argc, argv), argc - 1);
	init_stacks(&stb, "b", NULL, 0);
	if (check_sorted(&sta))
		push_swap_a(&cmd, &sta, &stb, sta.len);
	ft_lst_reverse(&cmd);
	optimize(&cmd);
	ft_lstiter(cmd, print);
	ft_lstclear(&sta.top, free);
	ft_lstclear(&stb.top, free);
	ft_lstclear(&cmd, free);
	return (0);
}
