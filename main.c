#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

int	main(void)
{
	int	fd;
	int i = 0;
	char *line;

	fd = open("read_error.txt", O_RDONLY);
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	return (0);
}