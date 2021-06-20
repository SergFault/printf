#include "../includes/ft_printf.h"

static int	ft_rank(unsigned int num)
{
	int	rank;

	if (!(num))
		return (1);
	rank = 0;
	while (num > 0)
	{
		rank++;
		num /= 10;
	}
	return (rank);
}

char	*ft_itoua(int n)
{
	int				rank;
	unsigned int	num;
	char			*ret;

	if (n < 0)
		num = -n;
	else
		num = n;
	rank = ft_rank(num);
	ret = (char *)malloc(sizeof(char) * (rank + 1));
	if (!(ret))
		return (0);
	ret[rank] = '\0';
	while (num > 9)
	{
		ret[rank-- - 1] = (num % 10) + ('0');
		num /= 10;
	}
	ret[rank-- - 1] = (num) + ('0');
	num = 0;
	return (ret);
}
