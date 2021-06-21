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

static int	write_body(t_specs *specs, char *str, int strlen, int prefix)
{
	int	counter;

	counter = 0;
	if (prefix)
	{
		if (specs->specifier & UPX_SPEC)
			counter += ft_putstr_fd("0X", 1);
		else
			counter += ft_putstr_fd("0x", 1);
	}
	if (specs->precision > (strlen - prefix * 2))
		counter += ft_padding(specs->precision - (strlen - prefix * 2), '0');
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

void	string_resolver(unsigned long *ui,
	int *prefix, t_specs *specs, char **str)
{
	if ((specs->specifier & P_SPEC)
		&& (!(*ui == 0 && (!(specs->specifier & P_SPEC)))))
		*prefix = 1;
	if (!(specs->specifier & P_SPEC))
		*ui = (unsigned int)(*ui);
	if (specs->specifier & UPX_SPEC)
		*str = ft_ui_to_hex(*ui, UPPER, 0);
	else if (specs->specifier & X_SPEC)
		*str = ft_ui_to_hex(*ui, LOWER, 0);
	else if (specs->specifier & P_SPEC)
		*str = ft_ui_to_hex(*ui, LOWER, 0);
}

int	hex_processor(t_specs *specs, va_list va)
{
	int				counter;
	unsigned long	ui;
	int				strlen;
	char			*str;
	int				prefix;

	counter = 0;
	prefix = 0;
	if (specs->specifier & P_SPEC)
		ui = va_arg(va, unsigned long);
	else
		ui = va_arg(va, unsigned int);
	if ((specs->specifier & P_SPEC) && (ui == 0))
		str = ft_strdup("0x0");
	else if ((ui == 0 && specs->flag_dot) && specs->precision == 0)
		str = ft_strdup("");
	else
		string_resolver(&ui, &prefix, specs, &str);
	strlen = ft_strlen(str) + (prefix * 2);
	counter += left_padding(specs, strlen);
	counter += write_body(specs, str, strlen, prefix);
	counter += right_padding(specs, strlen);
	free(str);
	return (counter);
}
