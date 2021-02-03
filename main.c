#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("/Users/amilis/Documents/Projects/get_next_line_project/testerzz/Get_Next_Line_Tester/test/64bit_paragraph.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("[%d] [%s]\n", ret, line);
		free(line);
	}
	printf("[%d] [%s]\n", ret, line);
	ret = get_next_line(fd, &line);
	printf("[%d] [%s]\n", ret, line);
    free(line);
	close(fd);
	return (0);
}
