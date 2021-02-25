#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777)) == -1)
		ft_create_fail();
	
}