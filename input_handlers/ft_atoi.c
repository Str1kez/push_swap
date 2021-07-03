#include "input_handlers.h"

static	int	is_overflow(const long long *num, const int *sign)
{
	if (*sign && (*num > 2147483648))
		return (1);
	if (!*sign && (*num > 2147483647))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	if (invalid_check(str))
		return (-1);
	sign = 0;
	if (*str == '-')
		sign = 1;
	while (*(str + sign))
	{
		result *= 10;
		result += *str - 48;
		if (is_overflow(&result, &sign))
			return (-1);
		str++;
	}
	if (sign)
		return (-result);
	return (result);
}
