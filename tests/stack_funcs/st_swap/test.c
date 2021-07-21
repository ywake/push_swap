#include "stack.h"
#include "data.h"

void	print_str(void *str)
{
	ft_putendl_fd(str, 1);
}

void	print_num(void *data)
{
	ft_putnbr_fd(((t_data *)data)->val, 1);
	ft_putendl_fd("", 1);
}

void	print_len(t_stack *stack)
{
	ft_putstr_fd("len:", 1);
	ft_putnbr_fd(stack->len, 1);
	ft_putendl_fd("", 1);
}

void	print_btm(t_stack *stack)
{
	ft_putstr_fd("last:", 1);
	ft_putnbr_fd(get_value(stack->btm), 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_list	*cmd;
	t_stack	stack;
	t_stack	null_stack;

	cmd = NULL;
	list = make_data(argc, argv);
	stack = (t_stack){.name = "a", .len = argc - 1,
		.top = list, .btm = ft_lstlast(list)};
	st_swap(&cmd, &stack);
	ft_lstiter(cmd, print_str);
	ft_lstiter(stack.top, print_num);
	print_btm(&stack);
	print_len(&stack);
	list = NULL;
	null_stack.top = list;
	st_swap(NULL, &stack);
}
