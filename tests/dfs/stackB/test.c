#include "push_swap.h"

#include "libft.h"
#include "data.h"
#include "stack.h"
#include "debug.h"

void	print_cmd_stdout(void *str)
{
	ft_putendl_fd(str, 1);
}

int	main(int argc, char *argv[])
{
	t_list	*cmd;
	t_stack	sta;
	t_stack	stb;
	t_list	*list;

	ft_putendl_fd("test...", 2);
	list = make_data(2, (char *[]){"./push_swap", "999"});
	sta = (t_stack){.name = "a", .top = list, .len = 1};
	sta.btm = ft_lstlast(sta.top);
	list = make_data(2, (char *[]){"./push_swap", "888"});
	stb = (t_stack){.name = "b", .top = make_data(argc, argv), .len = argc};
	ft_lstadd_back(&stb.top, list);
	stb.btm = ft_lstlast(stb.top);
	cmd = NULL;
	put_stack(&sta, &stb);
	small_swap(&cmd, (t_stack *[ST_LEN]){&sta, &stb}, stb.len - 1, BB);
	put_stack(&sta, &stb);
	ft_lst_reverse(&cmd);
	ft_putnbr_fd(ft_lstsize(cmd), 2);
	ft_putendl_fd("", 2);
	ft_lstclear(&cmd, free);
	ft_lstclear(&sta.top, free);
	ft_lstclear(&stb.top, free);
	return (0);
}
