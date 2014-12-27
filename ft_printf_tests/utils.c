#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <project.h>

// t_stdout *strdout_init(void)
// {
// 	g_stdout = malloc(sizeof(t_stdout));	
// 	setbuf(stdout, NULL);					
// 	g_stdout->saved_fd = dup(1); 			
// 	pipe(g_stdout->p);						
// 	dup2(g_stdout->p[1], 1);
// 	return (g_stdout);
// }

// char	*strdout_output(t_stdout *g_stdout)
// {
// 	*(g_stdout->output) = '\0';
// 	dup2(g_stdout->saved_fd, 1);
// 	g_stdout->output[read(g_stdout->p[0], g_stdout->output, sizeof(g_stdout->output) - 1)] = 0;
// 	close(g_stdout->p[1]); close(g_stdout->p[0]); close(g_stdout->saved_fd);
// 	return (g_stdout->output);
// }

// void	strdout_save_printf_output(t_stdout *g_stdout)
// {
// 	strcpy(g_stdout->printf_out, strdout_output(g_stdout));
// }
// void	strdout_save_ft_printf_output(t_stdout *g_stdout)
// {
// 	strcpy(g_stdout->ft_printf_out, strdout_output(g_stdout));
// }

// void	strdout_del(t_stdout *g_stdout)
// {

// 	dup2(g_stdout->saved_fd, 1);
// 	close(g_stdout->p[1]);
// 	close(g_stdout->p[0]);
// 	close(g_stdout->saved_fd);
// 	free(g_stdout);
// }
// char	*printf_to_str(char *format, ...)
// {
// 	int		old_out;
// 	int		p[2];
// 	int		ret;
// 	char	*out1;
//     va_list args;

//     setbuf(stdout, NULL);
// 	out1 = malloc(100000);
// 	old_out = dup(1);					
// 	pipe(p);							
// 	dup2(p[1], 1);						

//     va_start(args, format);

//     // fprintf(stderr, "format: {%s}\n", format);
//     // fprintf(stderr, "va_arg: {%s}\n", va_arg(args, char *));
//     // fprintf(stderr, "va_arg: {%s}\n", va_arg(args, char *));
//     // fprintf(stderr, "va_arg: {%s}\n", va_arg(args, char *));
//     printf(format, args);
//     fflush(stdout);
//     va_end(args);

// 	dup2(old_out, 1);
// 	ret = read(p[0], out1, 100001);
// 	fprintf(stderr, "ret: %d\n", ret);
// 	out1[ret] = 0; 
// 	fprintf(stderr, "out1: %s\n", out1);
//     // fflush(stdout);
// 	close(p[1]);						
// 	close(p[0]);						
// 	close(old_out);	
// 	return (out1);
// }

// char	*printf_to_str(char *format, ...)
// {
// 	char *s;
//     va_list args;

//     // fflush(stdout);
//     fprintf(stderr, "=== printf ===\n");
//     va_start(args, format);
//     s = x_printf_to_str(printf, format, args);
//     fprintf(stderr, "format: {%s}\n", format);
//     fprintf(stderr, "va_arg: {%s}\n", va_arg(args, char *));
//     fprintf(stderr, "va_arg: {%s}\n", va_arg(args, char *));
//     fprintf(stderr, "%s\n", "here");
//     fprintf(stderr, "s: <%s>\n", s);
//     fprintf(stderr, "%s\n", "there");
//     fflush(stdout);
//     va_end(args);
// 	return s;
// }

// char	*ft_printf_to_str(char *format, ...)
// {
// 	char *s;
//     va_list args;

//     va_start(args, format);
//     s = x_printf_to_str(ft_printf, format, args);
//     fprintf(stderr, "ft_print: {%s}\n", s);
//     fprintf(stderr, "va_arg: {%s}\n", va_arg(args, char *));
//     fprintf(stderr, "va_arg: {%s}\n", va_arg(args, char *));
//     fflush(stdout);
//     va_end(args);
// 	return s;
// }
