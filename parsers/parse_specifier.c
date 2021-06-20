#include "../includes/ft_printf.h"

int	parse_specifier(t_specs *specs, const char **fstrptr)
{
	if (!(ft_strchr("iucspxdX", **fstrptr)))
		return (-1);
	if (**fstrptr == 'i')
		specs->specifier = specs->specifier | I_SPEC;
	else if (**fstrptr == 'u')
		specs->specifier = specs->specifier | U_SPEC;
	else if (**fstrptr == 'c')
		specs->specifier = specs->specifier | C_SPEC;
	else if (**fstrptr == 's')
		specs->specifier = specs->specifier | S_SPEC;
	else if (**fstrptr == 'p')
		specs->specifier = specs->specifier | P_SPEC;
	else if (**fstrptr == 'x')
		specs->specifier = specs->specifier | X_SPEC;
	else if (**fstrptr == 'X')
		specs->specifier = specs->specifier | UPX_SPEC;
	else if (**fstrptr == 'd')
		specs->specifier = specs->specifier | D_SPEC;
	return (1);
}
