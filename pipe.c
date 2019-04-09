#include <stdio.h>
#include <taskLib.h>
#include <ioLib.h>
#include <pipeDrv.h>
void task1(void)
{
	int fd;
	printf("THIS IS TASK1 WRITING MESSAGE TO PIPE\n");
	fd=open("/pipe/mypipe",O_RDWR,0);
	write(fd,"spilo",5);
	close(fd);
}
void task2(void)
{
	int fd;
	char MSG[10];
	printf("THIS IS TASK2 READING MESSAGE\n");
	fd=open("/pipe/mypipe",O_RDONLY,0);
	read(fd,MSG,10);
	printf("MESSAGE FROM TASK1 IS READ AS :%s\n",MSG);
	close(fd);
}
void root(void)
{
	int tid1,tid2;
	pipeDevCreate("/pipe/mypipe",5,10);
	tid1=taskSpawn("task1",100,0,1024,(void*)task1,0,0,0,0,0,0,0,0,0,0);
	tid2=taskSpawn("task2",120,0,1024,(void*)task2,0,0,0,0,0,0,0,0,0,0);
}

