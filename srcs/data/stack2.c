#include "stack.h"

#include "libft.h"
#include "data.h"

void	st_double(t_list **cmd, void (*st_any)(), t_stack *sta, t_stack *stb)
{
	st_any(NULL, sta);
	st_any(NULL, stb);
	if (cmd)
	{
		if (st_any == st_swap)
			add_cmd(cmd, "s", "s");
		if (st_any == st_rotate)
			add_cmd(cmd, "r", "r");
		if (st_any == st_rrotate)
			add_cmd(cmd, "rr", "r");
	}
}

bool	is_sorted(t_stack *stack)
{
	t_list	*cur;

	cur = stack->top;
	while (cur && cur->next)
	{
		if (get_value(cur) > get_value(cur->next))
			return (false);
		cur = cur->next;
	}
	return (true);
}
