#include <stdio.h>
#include <msgQLib.h>
#include <taskLib.h>
MSG_Q_ID id;
void task1()
{
	int recret;
	char buf[10];
	printf("waiting for 1st msg\n");
	recret=msgQReceive(id,buf,10,WAIT_FOREVER);
	printf("1st msg Received = %s\n",buf);
}
void task2()
{
	STATUS senret;
	printf("sending msg (spilo1)\n");
	senret=msgQSend(id,"spilo1",6,WAIT_FOREVER,MSG_PRI_NORMAL);
}
void root()
{
	int taskid1,taskid2;
	id=msgQCreate(5,10,MSG_Q_FIFO);
	taskid1=taskSpawn("task1",101,NULL,512,(void*)&task1,0,0,0,0,0,0,0,0,0,0);
	taskid1=taskSpawn("task2",103,NULL,512,(void*)&task2,0,0,0,0,0,0,0,0,0,0);
	printf("task 1 id = %d\n",taskid1);	
	printf("task 2 id = %d\n",taskid2);
}