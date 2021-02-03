#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	char	*line;
	int 	fd1, fd2, fd3;
	int		ret1, ret2, ret3;

	ret1 = 1;
	ret2 = 2;
	ret3 = 3;
	fd1 = open("/Users/amilis/Documents/Projects/get_next_line_project/GNL_github/foo", O_RDONLY);
	fd2 = open("/Users/amilis/Documents/Projects/get_next_line_project/GNL_github/bar", O_RDONLY);
	fd3 = open("/Users/amilis/Documents/Projects/get_next_line_project/GNL_github/baz", O_RDONLY);

	while (ret1 > 0 || ret2 > 0 || ret3 > 0)
	{
		if (ret1 > 0)
		{
			ret1 = get_next_line(fd1, &line);
			printf("fd1 : [%d] [%s]\n", ret1, line);
		}
		if (ret2 > 0)
		{
			ret2 = get_next_line(fd2, &line);
			printf("fd2 : [%d] [%s]\n", ret2, line);
		}
		if (ret3 > 0)
		{
			ret3 = get_next_line(fd3, &line);
			printf("fd3 : [%d] [%s]\n", ret3, line);
		}
	}
	return (0);
}
