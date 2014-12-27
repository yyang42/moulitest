
#ifndef CAPTURE_H
# define CAPTURE_H

typedef struct s_cap_stdout
{
	int target_fd;
	int saved_fd;
	int out_pipe[2];
	char buffer[10000];

} t_cap_stdout;

t_cap_stdout	*capture_stdout_create(int target_fd);
void			capture_stdout(t_cap_stdout *cap);
char			*capture_stdout_get_buffer(t_cap_stdout *cap);
void			capture_stdout_destroy(t_cap_stdout *cap);

#endif