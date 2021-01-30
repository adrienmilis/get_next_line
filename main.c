#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("/Users/adrienmilis/Documents/19/Projects/get_next_line/GNL_github/42TESTERS-GNL/files/empty_lines", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("[%d] [%s]\n", ret, line);
		free(line);
	}
	printf("[%d] [%s]\n", ret, line);
    free(line);
	close(fd);
	return (0);
}
