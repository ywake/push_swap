#include "stack.h"
#include "push_swap.h"

void	print(void *num)
{
	ft_putnbr_fd(*(int *)num, 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char *argv[])
{
	t_list	*list_a;
	t_stack	stack_a;
	t_list	*list_b;
	t_stack	stack_b;

	list_a = make_data(argc, argv);
	stack_a.top = &list_a;
	list_b = NULL;
	stack_b.top = &list_b;
	st_push(NULL, &stack_a, &stack_b);
	st_push(NULL, &stack_b, &stack_a);
	ft_lstiter(*stack_a.top, print);
	ft_putendl_fd("-", 1);
	ft_lstiter(*stack_b.top, print);
}
