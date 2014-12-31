#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <capture.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_LEN 1024

// t_cap_stdout	*capture_stdout_create(int target_fd)
// {
// 	t_cap_stdout *cap;
// 	extern int saved_stdout;

// 	cap = malloc(sizeof(t_cap_stdout));
// 	saved_stdout = dup(cap.target_fd); /* save stdout for display later */
// 	cap.target_fd = target_fd;
// 	*(out_buffer) = '\0';
// 	return (cap);
// }

int	out_pipe[2];
char out_buffer[10 * 1000];

void	capture_stdout(int target_fd)
{
	extern int saved_stdout;

	if( pipe(out_pipe) != 0 ) {          /* make a pipe */
		exit(1);
	}
	saved_stdout = dup(target_fd); /* save stdout for display later */
	dup2(out_pipe[1], target_fd);   /* redirect stdout to the pipe */
	close(out_pipe[1]);
}

static void capture_unblock_fd(int fd)
{

	int flags = fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);

}

char	*capture_stdout_get_buffer(void)
{
	int ret;
	fflush(stdout);

	capture_unblock_fd(out_pipe[0]);
	*(out_buffer) = '\0';
	ret = read(out_pipe[0], out_buffer, MAX_LEN); /* read from pipe into buffer */
	out_buffer[ret] = '\0';
	return (out_buffer);
}

void			capture_stdout_destroy(void)
{
	extern int saved_stdout;
	dup2(saved_stdout, STDOUT_FILENO);  /* reconnect stdout for testing */
	// free(cap);
}
