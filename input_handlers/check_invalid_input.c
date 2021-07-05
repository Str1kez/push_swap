#include "input_handlers.h"

int	check_invalid_input(const char *arg)
{
	if (!ft_isdigit(*arg) && !(*arg == '-' && ft_isdigit(*(arg + 1))))
		return (1);
	if (*arg == '-')
		arg++;
	while (*arg)
		if (!ft_isdigit(*arg++))
			return (1);
	return (0);
}
