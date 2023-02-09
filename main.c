#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
} */

int	main(void)
{
	int	fd;
	int i = 0;
	char *line;

	fd = open("test", O_RDONLY);
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	return (0);
}