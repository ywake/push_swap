#include "libft.h"
#include "push_swap.h"

void	print(void *str)
{
	ft_putendl_fd(str, 1);
}

int	main(int argc, char *argv[])
{
	t_list	*cmd;

	cmd = NULL;
	while (--argc)
		ft_lstadd_front(&cmd, ft_lstnew(ft_strdup(argv[argc])));
	rm_nonsense(&cmd);
	ft_lstiter(cmd, print);
	ft_lstclear(&cmd, free);
}
