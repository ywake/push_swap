#include "stack.h"
#include "data.h"

void	print_str(void *str)
{
	ft_putendl_fd(str, 1);
}

void	print_num(void *num)
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
	t_list	*cmd;
	t_list	*list;
	t_stack	stack;
	t_stack	null_stack;

	cmd = NULL;
	list = make_data(argc, argv);
	stack.top = list;
	stack.name = "a";
	stack.len = argc - 1;
	st_rotate(&cmd, &stack);
	ft_lstiter(cmd, print_str);
	ft_lstiter(stack.top, print_num);
	print_len(&stack);
	list = NULL;
	null_stack.top = list;
	st_rotate(NULL, &stack);
}
