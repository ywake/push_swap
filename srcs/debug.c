#include "debug.h"

#include "data.h"
#include "stack.h"
#include "logging.h"

void	print_num(void *data)
{
	if (((t_data *)data)->is_start)
		ft_putstr_fd(BOLD, 2);
	ft_putnbr_fd(((t_data *)data)->val, 2);
	if (((t_data *)data)->is_start)
		ft_putstr_fd(END, 2);
	ft_putstr_fd(" ", 2);
}

void	put_stack(t_stack *sta, t_stack *stb)
{
	ft_putstr_fd("sta: ", 2);
	ft_lstiter(sta->top, print_num);
	ft_putendl_fd("", 2);
	ft_putstr_fd("stb: ", 2);
	ft_lstiter(stb->top, print_num);
	ft_putendl_fd("\n---", 2);
}
