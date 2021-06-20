#include "../includes/ft_printf.h"

void	parse_flags(t_specs *specs, const char **fstr)
{
	while (ft_strchr("-0", **fstr))
	{
		if (**fstr == '0')
			specs->flag_zero = 1;
		else if (**fstr == '-')
			specs->flag_minus = 1;
		(*fstr)++;
	}
}
