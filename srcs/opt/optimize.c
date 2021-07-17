#include "push_swap.h"

#include "stack.h"
#include "libft.h"

enum e_count_opt
{
	xa,
	xb,
	xx,
	len,
};

enum e_lists_opt
{
	start,
	end,
	save,
	list_len,
};

void	s_init(int cnt[len], t_list *lst[list_len], char *str[len], char *cmd)
{
	cnt[xa] = 0;
	cnt[xb] = 0;
	lst[start] = NULL;
	lst[end] = NULL;
	if (str == NULL)
		return ;
	str[xa] = ft_strjoin(cmd, "a");
	str[xb] = ft_strjoin(cmd, "b");
	if (ft_strncmp(cmd, "rr", 3) == 0)
		str[xx] = ft_strjoin(cmd, "r");
	else
		str[xx] = ft_strjoin(cmd, cmd);
}

void	s_del(char *str[len])
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
}

enum	e_abbr
{
	prev,
	mid,
	abbr_len,
};

t_list	*abbr(int cnt[len], t_list *lst[list_len], char *str[len])
{
	t_list	*pos[2];

	if (cnt[xa] * cnt[xb] != 0)
	{
		pos[mid] = NULL;
		while (cnt[xa] && cnt[xb] && cnt[xa]-- && cnt[xb]--)
			add_cmd(&pos[mid], str[xx], "");
		while (cnt[xa]--)
			add_cmd(&pos[mid], str[xa], "");
		while (cnt[xb]--)
			add_cmd(&pos[mid], str[xb], "");
		pos[prev] = ft_lst_at(lst[save],
				ft_lstget_index(lst[save], lst[start]) - 1);
		if (lst[save] == lst[start])
			lst[save] = pos[mid];
		else
			pos[prev]->next = pos[mid];
		ft_lstadd_back(&pos[mid], lst[end]->next);
		lst[end]->next = NULL;
		ft_lstclear(&lst[start], free);
	}
	s_init(cnt, lst, NULL, NULL);
	return (lst[save]);
}

void	search(t_list **cmd, char *cmdstr)
{
	int		count[3];
	t_list	*lst[3];
	char	*str[3];
	int		cmp[3];

	lst[save] = *cmd;
	s_init(count, lst, str, cmdstr);
	while (*cmd)
	{
		cmp[xa] = ft_strncmp((*cmd)->content, str[xa], ft_strlen(str[xa]) + 1);
		cmp[xb] = ft_strncmp((*cmd)->content, str[xb], ft_strlen(str[xb]) + 1);
		if ((!cmp[xa] && ++count[xa]) || (!cmp[xb] && ++count[xb]))
		{
			if (lst[start] == NULL)
				lst[start] = *cmd;
			lst[end] = *cmd;
		}
		else
			lst[save] = abbr(count, lst, str);
		*cmd = (*cmd)->next;
	}
	lst[save] = abbr(count, lst, str);
	s_del(str);
	*cmd = lst[save];
}

void	optimize(t_list **cmd)
{
	search(cmd, "s");
	search(cmd, "r");
	search(cmd, "rr");
}
