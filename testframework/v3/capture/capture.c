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

	cap = malloc(sizeof(t_cap_stdout));
	cap->saved_fd = dup(cap->target_fd); /* save stdout for display later */
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

char	*capture_stdout_get_buffer(t_cap_stdout *cap)
{
	int ret;
	fflush(stdout);

	ret = read(cap->out_pipe[0], cap->buffer, MAX_LEN); /* read from pipe into buffer */
	cap->buffer[ret] = '\0';

	return (cap->buffer);
}

void			capture_stdout_destroy(t_cap_stdout *cap)
{
	dup2(cap->saved_fd, cap->target_fd);  /* reconnect stdout for testing */
	free(cap);
}

// int main (int argc, char* argv[])
// {
// 	t_cap_stdout *cap;

// 	cap = capture_stdout_create(STDOUT_FILENO);
// 	capture_stdout(cap);

//   	printf("[stdout] printf\n");

// 	fprintf(stderr, "%s", capture_stdout_get_buffer(cap));
// 	// fprintf(stdout, "%s\n", capture_stdout_get_buffer(cap));

//   	write(1, "[stdout] write1\n", 16);
// 	fprintf(stderr, "%s", capture_stdout_get_buffer(cap));
//   	write(1, "[stdout] write2\n", 16);
// 	fprintf(stderr, "%s", capture_stdout_get_buffer(cap));
//   	write(1, "[stdout] write3\n", 16);
// 	fprintf(stderr, "%s", capture_stdout_get_buffer(cap));
//   	write(1, "[stdout] write4\n", 16);
// 	fprintf(stderr, "%s", capture_stdout_get_buffer(cap));

// 	capture_stdout_destroy(cap);

// 	printf("[stdout] restored\n");
// 	return 0;
// }

