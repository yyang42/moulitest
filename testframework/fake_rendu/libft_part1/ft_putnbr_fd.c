#include <libft.h>
void	ft_putnbr_fd(int n, int fd)
{
	(void)n;
	(void)fd;
	write(fd, "123", 1);
}
