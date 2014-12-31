#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <capture.h>

#define BUF_SIZE 1024
#define MAX_LEN 1024

t_cap_stdout	*capture_stdout_create(int target_fd)
{
	t_cap_stdout *cap;
	extern int saved_stdout;

	cap = malloc(sizeof(t_cap_stdout));
	saved_stdout = dup(cap->target_fd); /* save stdout for display later */
	cap->target_fd = target_fd;
	*(cap->buffer) = '\0';
	return (cap);
}

void	capture_stdout(t_cap_stdout *cap)
{
	if( pipe(cap->out_pipe) != 0 ) {          /* make a pipe */
		exit(1);
	}
	dup2(cap->out_pipe[1], cap->target_fd);   /* redirect stdout to the pipe */
	close(cap->out_pipe[1]);
}

static void capture_unblock_fd(int fd)
{

	int flags = fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);

}

char	*capture_stdout_get_buffer(t_cap_stdout *cap)
{
	int ret;
	fflush(stdout);

	capture_unblock_fd(cap->out_pipe[0]);
	*(cap->buffer) = '\0';
	ret = read(cap->out_pipe[0], cap->buffer, MAX_LEN); /* read from pipe into buffer */
	cap->buffer[ret] = '\0';
	return (cap->buffer);
}

void			capture_stdout_destroy(t_cap_stdout *cap)
{
	extern int saved_stdout;

	dup2(saved_stdout, cap->target_fd);  /* reconnect stdout for testing */
	free(cap);
}
