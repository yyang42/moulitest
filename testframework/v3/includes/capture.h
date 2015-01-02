
#ifndef CAPTURE_H
# define CAPTURE_H

typedef struct s_cap_stdout
{
	int target_fd;
	int saved_fd;
	int out_pipe[2];
	char buffer[10000];

} t_cap_stdout;

// t_cap_stdout	*capture_stdout_create(int target_fd);
void			capture_stdout(void);
char			*capture_stdout_get_buffer(void);
void			capture_stdout_destroy(void);
void			capture_close_saved_stdout(void);

#endif