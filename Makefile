all:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c && ./a.out

1:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c && ./a.out

2:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=2 main.c get_next_line.c get_next_line_utils.c && ./a.out

5:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=5 main.c get_next_line.c get_next_line_utils.c && ./a.out

6:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=6 main.c get_next_line.c get_next_line_utils.c && ./a.out

20:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=20 main.c get_next_line.c get_next_line_utils.c && ./a.out

25:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=25 main.c get_next_line.c get_next_line_utils.c && ./a.out

1024:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=1024 main.c get_next_line.c get_next_line_utils.c && ./a.out

5000:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=5000 main.c get_next_line.c get_next_line_utils.c && ./a.out

10000000:
	gcc -g -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c && ./a.out

leaks:
	valgrind --leak-check=full ./a.out

fsan:
	gcc -D BUFFER_SIZE=8 -fsanitize=address get_next_line.c get_next_line_utils.c main.c
