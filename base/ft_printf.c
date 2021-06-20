#include "../includes/ft_printf.h"

static int	parse_specs(t_specs *specs, const char **fstrptr, va_list ap)
{
	const char	*fstr;
	int			ret;

	ret = -1;
	fstr = *fstrptr;
	++(*fstrptr);
	parse_flags(specs, fstrptr);
	parse_width(specs, fstrptr, ap);
	parse_precision(specs, fstrptr, ap);
	ret = parse_specifier(specs, fstrptr);
	if (ret != 1)
		*fstrptr = fstr;
	return (ret);
}

static t_specs	init_specs(void)
{
	t_specs	specs;

	specs.flag_dot = 0;
	specs.precision = 0;
	specs.flag_zero = 0;
	specs.flag_minus = 0;
	specs.negative_signed = 0;
	specs.width = -1;
	specs.precision = 0;
	specs.specifier = NULL_SPEC;
	return (specs);
}

static int	write_manager(t_specs *specs, va_list va)
{
	int				counter;

	counter = 0;
	if (specs->specifier & PERCENT_SPEC)
		counter = percent_processor();
	if (specs->specifier & S_SPEC)
		counter = string_processor(specs, va);
	if ((specs->specifier & I_SPEC) || (specs->specifier & D_SPEC))
		counter = integer_processor(specs, va);
	if (specs->specifier & U_SPEC)
		counter = unsigned_processor(specs, va);
	if (specs->specifier & C_SPEC)
		counter = char_processor(specs, va);
	if ((specs->specifier & X_SPEC) || (specs->specifier & UPX_SPEC)
		|| (specs->specifier & P_SPEC))
		counter = hex_processor(specs, va);
	return (counter);
}

static unsigned	int	process_fstr(const char **fstrptr, va_list ap)
{
	int			counter;
	t_specs		specs;

	specs = init_specs();
	counter = 0;
	if ((parse_specs(&specs, fstrptr, ap)) == -1)
		counter = parse_fail_processor(fstrptr);
	else
		counter = write_manager(&specs, ap);
	return (counter);
}

int	ft_printf(const char *fstr, ...)
{
	unsigned int	counter;
	va_list			ap;

	counter = 0;
	va_start(ap, fstr);
	while (*fstr)
	{
		if (*fstr == '%')
			counter += process_fstr(&fstr, ap);
		else
		{
			ft_putchar_fd(*fstr, 1);
			counter++;
			fstr++;
		}
	}
	va_end(ap);
	return (counter);
}
