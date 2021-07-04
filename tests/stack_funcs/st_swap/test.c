#include "stack.h"
#include "push_swap.h"

void	print(void *num)
{
	ft_putnbr_fd(*(int *)num, 1);
	ft_putendl_fd("", 1);
}

void	print_len(t_stack *stack)
{
	ft_putstr_fd("len:", 1);
	ft_putnbr_fd(stack->len, 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_stack	stack;
	t_stack	null_stack;

	list = make_data(argc, argv);
	stack.top = &list;
	stack.len = argc - 1;
	st_swap(NULL, &stack);
	ft_lstiter(*stack.top, print);
	print_len(&stack);
	list = NULL;
	null_stack.top = &list;
	st_swap(NULL, &stack);
}
