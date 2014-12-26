#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_printf_to_str(char *format, ...)
{
	int		out;
	int		p[2];
	char	*buf;
    va_list args;

	buf = malloc(100 * 1000);
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

    va_start(args, format);
    ft_printf(format, args);
    va_end(args);

	dup2(out, 1);
	read(p[0], buf, 100 * 1000);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	return (buf);
}

char	*x_printf_to_str(int (*f)(const char *fmt, ...), const char *format, ...)
{
	int		out;
	int		p[2];
	char	*buf;
    va_list args;

	buf = malloc(100 * 1000);
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

    va_start(args, format);
    ft_printf(format, args);
    va_end(args);

	dup2(out, 1);
	read(p[0], buf, 100 * 1000);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	return (buf);
}

char	*printf_to_str(char *format, ...)
{
	char *s;
    va_list args;

    va_start(args, format);
    s = x_printf_to_str(printf, format, args);
    va_end(args);

	return s;
}
