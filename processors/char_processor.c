#include "../includes/ft_printf.h"

static int	left_padding(t_specs *specs, int strlen)
{
	int	counter;

	counter = 0;
	if (specs->flag_minus)
		return (0);
	counter += ft_padding(specs->width - strlen, ' ');
	return (counter);
}

static int	right_padding(t_specs *specs, int strlen)
{
	int	counter;

	if (!(specs->flag_minus))
		return (0);
	counter = ft_padding(specs->width - strlen, ' ');
	return (counter);
}

int	char_processor(t_specs *specs, va_list va)
{
	int		counter;
	char	ch;

	counter = 0;
	ch = (char)va_arg(va, int);
	counter += left_padding(specs, 1);
	write(1, &ch, 1);
	counter++;
	counter += right_padding(specs, 1);
	return (counter);
}
