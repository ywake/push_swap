#include "push_swap.h"

#include "stack.h"
#include "libft.h"

enum e_count_opt
{
	XA,
	XB,
	XX,
	LEN,
};

enum e_lists_opt
{
	START,
	END,
	SAVE,
	LIST_LEN,
};

void	s_init(int cnt[LEN], t_list *lst[LIST_LEN], char *str[LEN], char *cmd)
{
	cnt[XA] = 0;
	cnt[XB] = 0;
	lst[START] = NULL;
	lst[END] = NULL;
	if (str == NULL)
		return ;
	str[XA] = ft_strjoin(cmd, "a");
	str[XB] = ft_strjoin(cmd, "b");
	if (ft_strcmp(cmd, "rr") == 0)
		str[XX] = ft_strjoin(cmd, "r");
	else
		str[XX] = ft_strjoin(cmd, cmd);
}

void	s_del(char *str[LEN])
{
	int	i;

	i = 0;
	while (i < LEN)
	{
		free(str[i]);
		i++;
	}
}

enum	e_abbr
{
	PREV,
	MID,
	ABBR_LEN,
};

t_list	*abbr(int cnt[LEN], t_list *lst[LIST_LEN], char *str[LEN])
{
	t_list	*pos[ABBR_LEN];

	if (cnt[XA] * cnt[XB] != 0)
	{
		pos[MID] = NULL;
		while (cnt[XA] && cnt[XB] && cnt[XA]-- && cnt[XB]--)
			add_cmd(&pos[MID], str[XX], "");
		while (cnt[XA]--)
			add_cmd(&pos[MID], str[XA], "");
		while (cnt[XB]--)
			add_cmd(&pos[MID], str[XB], "");
		pos[PREV] = ft_lst_at(lst[SAVE],
				ft_lstget_index(lst[SAVE], lst[START]) - 1);
		if (lst[SAVE] == lst[START])
			lst[SAVE] = pos[MID];
		else
			pos[PREV]->next = pos[MID];
		ft_lstadd_back(&pos[MID], lst[END]->next);
		lst[END]->next = NULL;
		ft_lstclear(&lst[START], free);
	}
	s_init(cnt, lst, NULL, NULL);
	return (lst[SAVE]);
}

void	search(t_list **cmd, char *cmdstr)
{
	int		count[LEN];
	t_list	*lst[LIST_LEN];
	char	*str[LEN];
	int		cmp[LEN];

	lst[SAVE] = *cmd;
	s_init(count, lst, str, cmdstr);
	while (*cmd)
	{
		cmp[XA] = ft_strcmp((*cmd)->content, str[XA]);
		cmp[XB] = ft_strcmp((*cmd)->content, str[XB]);
		if ((!cmp[XA] && ++count[XA]) || (!cmp[XB] && ++count[XB]))
		{
			if (lst[START] == NULL)
				lst[START] = *cmd;
			lst[END] = *cmd;
		}
		else
			lst[SAVE] = abbr(count, lst, str);
		*cmd = (*cmd)->next;
	}
	lst[SAVE] = abbr(count, lst, str);
	s_del(str);
	*cmd = lst[SAVE];
}

void	optimize(t_list **cmd)
{
	search(cmd, "s");
	search(cmd, "r");
	search(cmd, "rr");
}
