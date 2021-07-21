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

void	print_btm(t_stack *stack)
{
	ft_putstr_fd("last:", 1);
	if (stack->btm == NULL)
		ft_putstr_fd("(null)", 1);
	else
		ft_putnbr_fd(get_value(stack->btm), 1);
	ft_putendl_fd("", 1);
}

int	main(int argc, char *argv[])
{
	t_list	*cmd;
	t_list	*list;
	t_stack	stack_a;
	t_stack	stack_b;

	cmd = NULL;
	list = make_data(argc, argv);
	stack_a = (t_stack){.name = "a", .len = argc - 1,
		.top = list, .btm = ft_lstlast(list)};
	stack_b = (t_stack){.name = "b", .len = 0, .top = NULL, .btm = NULL};
	st_push(&cmd, &stack_a, &stack_b);
	st_push(&cmd, &stack_b, &stack_a);
	st_push(&cmd, &stack_b, &stack_a);
	ft_lstiter(cmd, print_str);
	ft_lstiter(stack_a.top, print_num);
	print_btm(&stack_a);
	print_len(&stack_a);
	ft_putendl_fd("-", 1);
	ft_lstiter(stack_b.top, print_num);
	print_btm(&stack_b);
	print_len(&stack_b);
}
