#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <fcntl.h>


int main(int argc, char **argv)
{

	int fd = open("token", O_RDONLY);

	char buf[4096 + 1];
	bzero(buf, sizeof(buf));

	read(fd, buf, 4096);
	
	printf("buf before %s\n", buf);
	int i;
	for (i = 0; i < strlen(buf); i++) {
		buf[i] -= i;
	}

	printf("decoded: %s\n", buf);

	return 0;
}
