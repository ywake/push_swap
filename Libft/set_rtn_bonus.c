#include "libft.h"

char	*set_rtn(char **dest, char *source)
{
	*dest = source;
	return (source);
}

int	set_rtn_int(int *dest, int source)
{
	*dest = source;
	return (source);
}

long	set_rtn_long(long *dest, long source)
{
	*dest = source;
	return (source);
}
