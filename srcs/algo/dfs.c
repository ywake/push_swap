#include "push_swap.h"

#include "libft.h"
#include "stack.h"
#include "debug.h"
#include "logging.h"
#include <stdio.h>

void	do_cmd(t_state *state, char *cmd)
{
	if (cmd == NULL)
		return ;
	add_cmd(state->cmd, cmd, "");
	if (contain((char *[]){"sa", "ss", NULL}, cmd) + 1)
		st_swap(NULL, state->sta);
	if (contain((char *[]){"sb", "ss", NULL}, cmd) + 1)
		st_swap(NULL, state->stb);
	if (!ft_strcmp("pa", cmd))
		st_push(NULL, state->sta, state->stb);
	if (!ft_strcmp("pb", cmd))
		st_push(NULL, state->stb, state->sta);
	if (contain((char *[]){"ra", "rr", NULL}, cmd) + 1)
		st_rotate(NULL, state->sta);
	if (contain((char *[]){"rb", "rr", NULL}, cmd) + 1)
		st_rotate(NULL, state->stb);
	if (contain((char *[]){"rra", "rrr", NULL}, cmd) + 1)
		st_rrotate(NULL, state->sta);
	if (contain((char *[]){"rrb", "rrr", NULL}, cmd) + 1)
		st_rrotate(NULL, state->stb);
}

void	undo_cmd(t_state *state, char *cmd)
{
	ft_lstdrop(state->cmd, *state->cmd, free);
	if (cmd == NULL)
		return ;
	if (contain((char *[]){"sa", "ss", NULL}, cmd) + 1)
		st_swap(NULL, state->sta);
	if (contain((char *[]){"sb", "ss", NULL}, cmd) + 1)
		st_swap(NULL, state->stb);
	if (!ft_strcmp("pa", cmd))
		st_push(NULL, state->stb, state->sta);
	if (!ft_strcmp("pb", cmd))
		st_push(NULL, state->sta, state->stb);
	if (contain((char *[]){"ra", "rr", NULL}, cmd) + 1)
		st_rrotate(NULL, state->sta);
	if (contain((char *[]){"rb", "rr", NULL}, cmd) + 1)
		st_rrotate(NULL, state->stb);
	if (contain((char *[]){"rra", "rrr", NULL}, cmd) + 1)
		st_rotate(NULL, state->sta);
	if (contain((char *[]){"rrb", "rrr", NULL}, cmd) + 1)
		st_rotate(NULL, state->stb);
}

bool	can_move(t_state *state, char *next)
{
	t_list	*sta;
	t_list	*stb;

	sta = state->sta->top;
	stb = state->stb->top;
	if ((!ft_strcmp(next, "pa") && !is_movable(state, stb))
		|| (!ft_strcmp(next, "pb") && !is_movable(state, sta)))
		return (false);
	if ((contain((char *[]){"sa", "ss", NULL}, next) + 1 && \
			(!is_movable(state, sta) || !is_movable(state, sta->next)))
		|| (contain((char *[]){"sb", "ss", NULL}, next) + 1 && \
			(!is_movable(state, stb) || !is_movable(state, stb->next))))
		return (false);
	if ((contain((char *[]){"ra", "rr", NULL}, next) + 1 && \
			!is_movable(state, sta))
		|| (contain((char *[]){"rb", "rr", NULL}, next) + 1 && \
			!is_movable(state, stb)))
		return (false);
	if ((contain((char *[]){"rra", "rrr", NULL}, next) + 1 && \
			!is_movable(state, state->sta->btm))
		|| (contain((char *[]){"rrb", "rrr", NULL}, next) + 1 && \
			!is_movable(state, state->stb->btm)))
		return (false);
	return (true);
}

bool	has_mean(char *cmd, char *next)
{
	char	**next_ng;

	next_ng = (char *[]){"sa", "sb", "ss", NULL};
	if ((cmd && !ft_strcmp(cmd, "sa") && contain(next_ng, next) + 1)
		|| (cmd && !ft_strcmp(cmd, "sb") && contain(next_ng, next) + 1)
		|| (cmd && !ft_strcmp(cmd, "ss") && contain(next_ng, next) + 1)
		|| (cmd && !ft_strcmp(cmd, "pa") && !ft_strcmp(next, "pb"))
		|| (cmd && !ft_strcmp(cmd, "pb") && !ft_strcmp(next, "pa"))
		|| (cmd && !ft_strcmp(cmd, "ra") && \
			contain((char *[]){"rb", "rra", "rrr", NULL}, next) + 1)
		|| (cmd && (!ft_strcmp(cmd, "rb") && \
			contain((char *[]){"ra", "rrb", "rrr", NULL}, next) + 1))
		|| (cmd && !ft_strcmp(cmd, "rr") && \
			contain((char *[]){"rrr", "rra", "rrb", NULL}, next) + 1)
		|| (cmd && !ft_strcmp(cmd, "rra") && \
			contain((char *[]){"rrb", "ra", "rr", NULL}, next) + 1)
		|| (cmd && !ft_strcmp(cmd, "rrb") && \
			contain((char *[]){"rra", "rb", "rr", NULL}, next) + 1)
		|| (cmd && !ft_strcmp(cmd, "rrr") && \
			contain((char *[]){"rr", "ra", "rb", NULL}, next) + 1))
		return (false);
	return (true);
}

void	dfs(t_state *state, char **cmds, char *cmd, size_t move_num)
{
	int		next;

	do_cmd(state, cmd);
	if (state->sta->len >= state->range
		&& ft_lst_at(state->sta->top, state->range) == state->a_next
		&& is_sorted(state->sta, state->range, asc))
	{
		if (state->find)
			ft_lstclear(&state->find, free);
		state->find = ft_lstndup(*state->cmd, -1);
		state->search_max = move_num;
	}
	next = 0;
	while (move_num < state->search_max && next < 11)
	{
		if (can_move(state, cmds[next]) && has_mean(cmd, cmds[next]))
			dfs(state, cmds, cmds[next], move_num + 1);
		next++;
	}
	undo_cmd(state, cmd);
}
