#include "../includes/ft_printf.h"

int	ft_padding(int width, char c)
{
	int	counter;

	counter = 0;
	while (width-- > 0)
	{
		ft_putchar_fd(c, 1);
		counter++;
	}
	return (counter);
}
