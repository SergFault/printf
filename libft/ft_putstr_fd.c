#include "../includes/ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	if (!s)
		return (counter);
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
		counter++;
	}
	return (counter);
}
