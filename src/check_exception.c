#include "src.h"

void	check_exception(int exc)
{
	if (exc == -1)
	{
		ft_putstr("Error\n");
		exit(1);
	}
}
