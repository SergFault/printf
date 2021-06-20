#include "../includes/ft_printf.h"

void	parse_precision(t_specs *specs, const char **fstrptr, va_list ap)
{
	if ((**fstrptr) != '.')
		return ;
	specs->flag_dot = 1;
	(*fstrptr)++;
	if (**fstrptr == '*')
	{
		specs->precision = va_arg(ap, int);
		(*fstrptr)++;
	}
	else if (ft_strchr("0123456789", **fstrptr))
	{
		specs-> precision = ft_atoi(*fstrptr);
		while (**fstrptr >= '0' && **fstrptr <= '9')
			(*fstrptr)++;
	}
}
