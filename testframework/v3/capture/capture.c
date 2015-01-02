#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <capture.h>
#include <errno.h>
#include <assert.h>

#define MAX_LEN 42000
#define BUF_SIZE MAX_LEN + 1

const int READ = 0;
const int WRITE = 1;
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

#include <unistd.h>
#define NO_FD_OPENED -1
int saved_stdout = NO_FD_OPENED;

void capture_close_saved_stdout(void)
{
	extern int saved_stdout;

	if (saved_stdout != NO_FD_OPENED)
	{
		// fprintf(stderr, "== close %d ==\n", saved_stdout);
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout); /* important ! */
		saved_stdout = NO_FD_OPENED;
		close(out_pipe[READ]);
		close(out_pipe[WRITE]);
	}
}

void	capture_stdout(void)
{
	capture_close_saved_stdout();
	if( pipe(out_pipe) != 0 ) {          /* make a pipe */
		assert(0);
	}
	assert(saved_stdout < 100);
	saved_stdout = dup(STDOUT_FILENO); /* save stdout for display later */
	dup2(out_pipe[WRITE], STDOUT_FILENO);   /* redirect stdout to the pipe */
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
	ret = read(out_pipe[READ], out_buffer, MAX_LEN); /* read from pipe into buffer */
	out_buffer[ret] = '\0';
	return (out_buffer);
}

void			capture_stdout_destroy(void)
{
	extern int saved_stdout;
	dup2(saved_stdout, STDOUT_FILENO);  /* reconnect stdout for testing */
	capture_close_saved_stdout();

	// free(cap);
}
