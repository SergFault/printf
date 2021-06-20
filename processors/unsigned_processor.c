#include "../includes/ft_printf.h"

static int	left_padding(t_specs *specs, int strlen)
{
	int		counter;
	char	pad_char;
	int		effect_strlen;

	if (specs->precision > strlen)
		effect_strlen = specs->precision;
	else
		effect_strlen = strlen;
	counter = 0;
	if (specs->flag_minus)
		return (0);
	if (specs->flag_zero && !specs->flag_dot)
		pad_char = '0';
	else
		pad_char = ' ';
	counter += ft_padding(specs->width - effect_strlen, pad_char);
	return (counter);
}

static int	write_body(t_specs *specs, char *str, int strlen)
{
	int	counter;

	counter = 0;
	if (specs->precision > strlen)
		counter += ft_padding(specs->precision - strlen, '0');
	ft_putstr_fd(str, 1);
	counter += ft_strlen(str);
	return (counter);
}

static int	right_padding(t_specs *specs, int strlen)
{
	int	counter;
	int	effect_strlen;

	if (!(specs->flag_minus))
		return (0);
	if (specs->precision > strlen)
		effect_strlen = specs->precision;
	else
		effect_strlen = strlen;
	counter = ft_padding(specs->width - effect_strlen, ' ');
	return (counter);
}

int	unsigned_processor(t_specs *specs, va_list va)
{
	int				counter;
	unsigned int	ui;
	int				strlen;
	char			*str;

	counter = 0;
	ui = va_arg(va, unsigned int);
	if (specs->flag_dot && !specs->precision && !ui)
		str = ft_strdup("");
	else
		str = ft_utoa(ui);
	strlen = ft_strlen(str);
	counter += left_padding(specs, strlen);
	counter += write_body(specs, str, strlen);
	counter += right_padding(specs, strlen);
	free(str);
	return (counter);
}
