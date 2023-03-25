#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd1, fd2;
    
    fd1 = open("./test_mandatory.txt", O_RDONLY);
	fd2 = open("./test_bonus.txt", O_RDONLY);
    
	while(1)
	{
		line = get_next_line(fd1);
		if (line)
			printf("%d : %s", fd1, line);
		else
			break;
		free(line);
		line = get_next_line(fd2);
		if (line)
			printf("%d : %s", fd2, line);
		else
			break;
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
}