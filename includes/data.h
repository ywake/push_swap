#ifndef DATA_H
# define DATA_H

# include "libft.h"
# include <stdbool.h>

enum e_type
{
	START = -1,
	MID,
	END,
};

typedef struct s_data
{
	int		val;
	bool	is_start;
}	t_data;

t_list	*make_data(int argc, char *argv[]);
int		get_value(t_list *list);
bool	is_start(t_list *list);

#endif
