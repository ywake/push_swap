#include "checker.h"

#include "error.h"
#include "data.h"
#include "stack.h"
#include <unistd.h>

void	get_cmd(t_list **cmd)
{
	char	*line;
	int		rtn;
	t_list	*elem;

	while (set_rtn_int(&rtn, get_next_line(STDIN_FILENO, &line)))
	{
		if (rtn == -1 || !set_rtn((char **)&elem, (char *)ft_lstnew(line)))
			error();
		ft_lstadd_front(cmd, elem);
		line = NULL;
	}
	ft_lst_reverse(cmd);
}

int	main(int argc, char *argv[])
{
	t_stack	sta;
	t_stack	stb;
	t_list	*cmd;

	if (argc == 1)
		return (0);
	sta = (t_stack){.top = make_data(argc, argv), .len = argc - 1};
	sta.btm = ft_lstlast(sta.top);
	stb = (t_stack){};
	cmd = NULL;
	get_cmd(&cmd);
	if (checker(cmd, &sta, &stb))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&sta.top, free);
	ft_lstclear(&stb.top, free);
	ft_lstclear(&cmd, free);
}
