#include "push_swap.h"

#include "libft.h"
#include "stack.h"
#include "data.h"
#include "debug.h"

bool	is_movable(t_state *state, t_list *elem)
{
	int	i;

	if (elem == NULL)
		return (false);
	i = 0;
	while (state->movable[i])
	{
		if (state->movable[i] == elem)
			return (true);
		i++;
	}
	return (false);
}

void	small_swap(t_list **cmd, t_stack *st[ST_LEN], int r, enum e_stacks ope)
{
	t_state	state;
	t_list	*cmd_tmp;
	t_list	**movable;
	char	**cmds;

	cmd_tmp = NULL;
	state = (t_state){.cmd = &cmd_tmp,
		.search_max = (int []){0, 1, 3, 5 + ope, 8 + !ope, 10}[r],
		.sta = st[AA], .stb = st[BB], .range = r,
		.a_next = ft_lst_at(st[AA]->top, r * !ope)};
	movable = (t_list *[]){NULL, NULL, NULL, NULL, NULL, NULL};
	while (r--)
		movable[r] = ft_lst_at(st[ope]->top, r);
	state.movable = movable;
	cmds = (char *[]){"ss", "sa", "sb", "pa", "pb", "rr", "ra", "rb", "rrr",
		"rra", "rrb", NULL};
	dfs(&state, cmds, NULL, 0);
	ft_lst_reverse(&state.find);
	simulate_stack(state.find, state.sta, state.stb);
	ft_lst_reverse(&state.find);
	ft_lstadd_back(&state.find, *cmd);
	*cmd = state.find;
}
