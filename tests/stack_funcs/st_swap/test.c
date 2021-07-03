#include "stack.h"
#include "push_swap.h"

void	print(void *num)
{
	ft_putnbr_fd(*(int *)num, 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_stack	stack;
	t_stack	null_stack;

	list = make_data(argc, argv);
	stack.top = &list;
	st_swap(NULL, &stack);
	ft_lstiter(*stack.top, print);
	list = NULL;
	null_stack.top = &list;
	st_swap(NULL, &stack);
}
