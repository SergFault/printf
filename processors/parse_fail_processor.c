#include "../includes/ft_printf.h"

int	parse_fail_processor(const char **str_ptr)
{
	int	counter;

	counter = 0;
	ft_putchar_fd('%', 1);
	counter++;
	(*str_ptr)++;
	return (counter);
}
