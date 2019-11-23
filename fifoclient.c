#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

char fname[256];

int main()
{
	int readfd,writefd;
	ssize_t n;
	char buff[512];
	printf("trying to connect to server... \n");
	writefd = open(FIFO1,O_WRONLY,0);
	readfd = open(FIFO2,O_RDONLY,0);
	printf("connected. \n");
	printf("Enter the filename to request from server \n");
	scanf("%s",fname);
	write(writefd,fname,strlen(fname));
	printf("Waiting for server to reply..\n");
	while((n = read(readfd,buff,512))>0)
	{
		write(1,buff,n);
	}
	close(readfd);
	close(writefd);
	
	return 0;
	
}