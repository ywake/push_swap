#ifndef VALIDATION_H
# define VALIDATION_H

# include "data.h"

int		cmp(t_data *a, t_data *b);
bool	is_valid_num(char *str1);
bool	has_duplicate(t_list *list);

#endif
