#include "libft.h"

/**
 * @brief A function that searches for [str] in a [array].
 * @return Returns the index if found, -1 if not found.
 */
int	contain(char **array, char *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (!ft_strncmp(array[i], str, -1))
			return (i);
		i++;
	}
	return (-1);
}
