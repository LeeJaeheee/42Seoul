#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char *line; 
	int fd;
	int i = 1;
    
    fd = open("./test_mandatory.txt", O_RDONLY);
    
	while(1)
	{
    	line = get_next_line(fd);
		printf("line %d : %s", i++, line);
        if (line == NULL)
        	break ;
		free(line);
	}
	close(fd);
	return (0);

}