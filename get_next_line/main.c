#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char *line; 
	int fd;
    
    fd = open("./test.txt", O_RDONLY);
    
	while(1)
	{
    	line = get_next_line(fd);
        if (line == NULL)
        	break ;
		printf("line : %s",line);
	}
	return (0);
}