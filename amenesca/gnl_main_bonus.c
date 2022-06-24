#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int 	fd1;
	int		fd2;
	char	*line;
	char	*line2;

	fd1 = open("texto.txt", O_RDONLY);
	fd2 = open("texto2.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line == NULL && line2 == NULL)
			break ;
		printf("%s\n%s\n", line, line2);
		free(line);
		free(line2);
	}
	return (0);
}
