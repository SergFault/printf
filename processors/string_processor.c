#include "../includes/ft_printf.h"

static int	put_n_str(char *str, int n)
{
	int	counter;

	counter = 0;
	while (str && *str && (n-- > 0))
	{
		ft_putchar_fd(*str++, 1);
		counter++;
	}
	return (counter);
}

static int	min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

static void	null_processor(char *str, t_specs *specs)
{
	if (!str)
	{
		if (specs->precision >= 6 || !specs->flag_dot)
			str = "(null)";
		else
			str = "";
	}
}

static void	process_struct(t_specs *specs)
{
	if (specs->flag_dot && specs->precision == -1)
		specs->precision = 0;
	if (specs->width == -1)
		specs->width = 0;
}

int	string_processor(t_specs *specs, va_list va)
{
	char	*str;
	int		counter;
	int		eff_strlen;

	counter = 0;
	str = va_arg(va, char *);
	if (specs->flag_dot && specs->precision < 0)
		specs->flag_dot = 0;
	null_processor(str, specs);
	process_struct(specs);
	if (specs->flag_dot && specs->precision >= 0)
		eff_strlen = min(ft_strlen(str), specs->precision);
	else
		eff_strlen = ft_strlen(str);
	if (specs->flag_minus)
	{
		counter = put_n_str(str, eff_strlen);
		counter += ft_padding(specs->width - eff_strlen, ' ');
	}
	else if (!(specs->flag_minus))
	{
		counter = ft_padding(specs->width - eff_strlen, ' ');
		counter += put_n_str(str, eff_strlen);
	}
	return (counter);
}
