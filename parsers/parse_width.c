#include "../includes/ft_printf.h"

void	parse_width(t_specs *specs, const char **fstr, va_list ap)
{
	if (!(ft_strchr("0123456789*", **fstr)))
		return ;
	if (**fstr == '*')
	{
		specs->width = va_arg(ap, int);
		if (specs->width < 0)
		{
			specs->width = -specs->width;
			specs->flag_minus = 1;
		}
		(*fstr)++;
	}
	else
	{
		specs->width = ft_atoi(*fstr);
		while (**fstr >= '0' && **fstr <= '9')
			(*fstr)++;
	}
}
