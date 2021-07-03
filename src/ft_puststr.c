#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
