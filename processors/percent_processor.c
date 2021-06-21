#include "../includes/ft_printf.h"

static int	left_padding(t_specs *specs, int strlen)
{
	int		counter;
	char	papdding_char;

	if (specs->flag_zero)
		papdding_char = '0';
	else
		papdding_char = ' ';
	counter = 0;
	if (specs->flag_minus)
		return (0);
	counter += ft_padding(specs->width - strlen, papdding_char);
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

int	percent_processor(t_specs *specs)
{
	int		counter;

	counter = 0;
	counter += left_padding(specs, 1);
	ft_putchar_fd('%', 1);
	counter++;
	counter += right_padding(specs, 1);
	return (counter);
}
