#include "../includes/ft_printf.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (!(dup))
		return (0);
	ft_strlcpy(dup, s, len * (sizeof(char)) + 1);
	return (dup);
}
