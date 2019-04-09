#include<taskLib.h>
#include<msgQLib.h>
#include<pipeDrv.h>
#include<ioLib.h>
int t1,t2,t3;
void task1()
{
 int fd;
    
   char inMsg[10];
    int len;

    fd = open ("/pipe/p1",O_RDWR,0644);

    write (fd, "hi", 10);
    len = read (fd, inMsg,10);
    printf("%s",inMsg);

    close (fd);
}
void root()
{
	pipeDevCreate("/pipe/p1",10,10); 
        t1=taskSpawn("task1",110,0,256,task1,0,0,0,0,0,0,0,0,0,0);
	
	

}