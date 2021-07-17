#include "stack.h"

#include "libft.h"

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
