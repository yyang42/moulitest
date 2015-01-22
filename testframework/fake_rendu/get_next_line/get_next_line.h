#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 7
# define MAX_BUFF_SIZE 8385531
# define MAX_PARALLEL_FILES 10000

# include <unistd.h>
# include <string.h>

int get_next_line(int const fd, char **line);

#endif
