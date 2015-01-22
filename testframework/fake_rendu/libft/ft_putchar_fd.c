#include <libft.h>
void	ft_putchar_fd(char c, int fd)
{
	(void)c;
	(void)fd;
	write(fd, "123", 1);
}
