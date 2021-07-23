#include "error.h"
#include "data.h"
#include "stack.h"

void	read_do_cmd(t_stack *sta, t_stack *stb)
{
	char	*cmd;
	int		rtn;
	char	**vaild_list;

	vaild_list = (char *[]){"ss", "sa", "sb", "pa", "pb", "rr", "ra", "rb",
		"rrr", "rra", "rrb", NULL};
	while (set_rtn_int(&rtn, get_next_line(STDIN_FILENO, &cmd)))
	{
		if (rtn == -1 || cmd == NULL)
			error();
		if (!do_cmd(NULL, (t_stack *[]){sta, stb}, vaild_list, cmd))
			error();
		free_set((void **)&cmd, NULL);
	}
	if (rtn == 0)
		free(cmd);
}

bool	checker(t_stack *sta, t_stack *stb)
{
	if (stb->len != 0)
		return (false);
	if (is_sorted(sta, -1, asc))
		return (true);
	return (false);
}

int	main(int argc, char *argv[])
{
	t_stack	sta;
	t_stack	stb;

	if (argc == 1)
		return (0);
	sta = (t_stack){.top = make_data(argc, argv), .len = argc - 1};
	sta.btm = ft_lstlast(sta.top);
	stb = (t_stack){};
	read_do_cmd(&sta, &stb);
	if (checker(&sta, &stb))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&sta.top, free);
	ft_lstclear(&stb.top, free);
}
