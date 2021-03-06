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

void	init_stack(t_stack *stack, char *name, t_list *list, int len)
{
	stack->name = name;
	stack->top = list;
	stack->len = len;
	stack->btm = ft_lstlast(list);
}

int	main(int argc, char *argv[])
{
	t_list	*cmd;
	t_stack	sta;
	t_stack	stb;

	cmd = NULL;
	if (argc == 1)
		return (0);
	init_stack(&sta, "a", make_data(argc, argv), argc - 1);
	init_stack(&stb, "b", NULL, 0);
	if (!is_sorted(&sta, -1, asc))
		push_swap_a(&cmd, &sta, &stb, sta.len);
	ft_lst_reverse(&cmd);
	while (rm_nonsense(&cmd))
		;
	optimize(&cmd);
	ft_lstiter(cmd, print);
	ft_lstclear(&sta.top, free);
	ft_lstclear(&stb.top, free);
	ft_lstclear(&cmd, free);
	return (0);
}
