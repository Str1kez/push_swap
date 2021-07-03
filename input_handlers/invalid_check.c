#include "input_handlers.h"

int	invalid_check(const char *arg)
{
	if (!ft_isdigit(*arg) && !(*arg == '-' && ft_isdigit(*(arg + 1))))
		return (1);
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (1);
	return (0);
}
