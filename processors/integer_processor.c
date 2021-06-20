#include "../includes/ft_printf.h"

static void	prepare_struct(t_specs *specs, int val)
{
	struct_processor(specs);
	if (val < 0)
	{
		specs->negative_signed = 1;
	}
}

static int	prt_pref(t_specs *specs)
{
	int	counter;

	counter = 0;
	if (specs->negative_signed)
		counter = ft_padding(1, '-');
	return (counter);
}

static int	print_body(char *str_val, t_specs *specs, int have_suffix)
{
	int	padding_precision;
	int	padding_width;
	int	counter;

	counter = 0;
	padding_precision = ft_max_int(0, specs->precision - ft_strlen(str_val));
	padding_width = ft_max_int(0, specs->width - ft_max_int(ft_strlen(str_val)
				+ padding_precision + have_suffix, specs->precision));
	if (specs->flag_minus)
		counter = prt_pref(specs)
			+ ft_padding(padding_precision, '0')
			+ ft_putstr_fd(str_val, 1) + ft_padding(padding_width, ' ');
	else
	{
		if (specs->flag_zero && !specs->flag_dot)
			counter = prt_pref(specs) + ft_padding(padding_width, '0')
				+ ft_padding(padding_precision, '0')
				+ ft_putstr_fd(str_val, 1);
		else
			counter = ft_padding(padding_width, ' ') + prt_pref(specs)
				+ ft_padding(padding_precision, '0')
				+ ft_putstr_fd(str_val, 1);
	}
	return (counter);
}

int	write_int(char *str_val, t_specs *specs)
{
	int	have_suffix;
	int	counter;

	counter = 0;
	have_suffix = 0;
	if (specs->negative_signed)
		have_suffix = 1;
	counter += have_suffix;
	counter = print_body(str_val, specs, have_suffix);
	return (counter);
}

int	integer_processor(t_specs *specs, va_list va)
{
	int		counter;
	int		value;
	char	*str_val;

	counter = 0;
	value = va_arg(va, int);
	prepare_struct(specs, value);
	if (value == 0 && specs->flag_dot && specs->precision == 0)
	{
		str_val = (char *)malloc(sizeof(char) * 1);
		*str_val = '\0';
	}
	else
		str_val = ft_itoua(value);
	counter = write_int(str_val, specs);
	free(str_val);
	return (counter);
}
