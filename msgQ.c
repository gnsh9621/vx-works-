#include <stdio.h>
#include <msgQLib.h>
#include <taskLib.h>
MSG_Q_ID id;
void task1()
{
	int recret;
	char buf[10];
	printf("waiting for 1st msg\n");
/*	recret=msgQReceive(id,buf,10,WAIT_FOREVER);*/
	recret=msgQReceive(id,buf,10,NO_WAIT);
	printf("1st msg Received = %s\n",buf);
	printf("waiting for 2nd msg\n");
	recret=msgQReceive(id,buf,10,WAIT_FOREVER);
	printf("2nd msg Received = %s\n",buf);
	printf("waiting for 3rd msg\n");
	recret=msgQReceive(id,buf,10,WAIT_FOREVER);
	printf("3rd msg Received = %s\n",buf);
}
void task2()
{
	STATUS senret;
	printf("sending 1st msg (spilo1)\n");
	senret=msgQSend(id,"spilo1",6,WAIT_FOREVER,MSG_PRI_NORMAL);
	printf("sending 2nd msg (spilo2)\n");
	senret=msgQSend(id,"spilo2",6,WAIT_FOREVER,MSG_PRI_NORMAL);
	printf("sending 3rd msg (spilo3)\n");
/*	senret=msgQSend(id,"spilo3",6,WAIT_FOREVER,MSG_PRI_NORMAL);*/
	senret=msgQSend(id,"spilo3",6,WAIT_FOREVER,MSG_PRI_URGENT);
}
void root()
{
	int taskid1,taskid2;
	id=msgQCreate(5,10,MSG_Q_FIFO);
/*	taskid1=taskSpawn("task1",101,NULL,512,(void*)&task1,0,0,0,0,0,0,0,0,0,0);*/
	taskid1=taskSpawn("task1",103,NULL,512,(void*)&task1,0,0,0,0,0,0,0,0,0,0);
	taskid2=taskSpawn("task2",102,NULL,512,(void*)&task2,0,0,0,0,0,0,0,0,0,0);
	printf("task 1 id = %d\n",taskid1);	
	printf("task 2 id = %d\n",taskid2);
}