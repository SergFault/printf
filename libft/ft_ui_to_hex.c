#include "../includes/ft_printf.h"

static int	get_rank(unsigned long long ull)
{
	int	rank;

	rank = 0;
	while (ull >= 16)
	{
		ull = ull / 16;
		rank++;
	}
	rank++;
	return (rank);
}

static char	hex_char(int i, int up_lo_flag)
{
	if (i >= 0 && i <= 9)
		return (i + '0');
	else if (up_lo_flag == 1)
		return (i - 10 + 'A');
	else
		return (i - 10 + 'a');
}

char	*ft_ui_to_hex(unsigned long ui, int up_lo_pref_flag, int prefix)
{
	char	*hex_str;
	int		rank;

	rank = get_rank(ui);
	 if (prefix)
		rank += 2;
	hex_str = (char *)malloc(sizeof(char) * (rank + 1));
	if (!hex_str)
		return (NULL);
	ft_memset(hex_str, 0, (rank + 1));
	if (!(hex_str))
		return (NULL);
	hex_str[rank] = '\0';
	while (ui > 15)
	{
		hex_str[--rank] = hex_char((ui % 16), up_lo_pref_flag);
		ui = ui / 16;
	}
	hex_str[--rank] = hex_char((ui), up_lo_pref_flag);
	 if (prefix)
	{
		hex_str[--rank] = 'x';
		hex_str[--rank] = '0';
	}
	return (hex_str);
}
