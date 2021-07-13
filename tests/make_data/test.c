#include "push_swap.h"

#include "libft.h"
#include "data.h"
#include <stdio.h>

void	print(void *data)
{
	ft_putnbr_fd(((t_data *)data)->val, 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char *argv[])
{
	t_list	*list;

	list = make_data(argc, argv);
	ft_lstiter(list, print);
	ft_lstclear(&list, free);
	return (0);
}
