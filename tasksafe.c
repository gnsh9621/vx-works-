#include <stdio.h>
#include <semLib.h>
#include <taskLib.h>

int taskid1,taskid2,taskid3;
SEM_ID semid1;
void task3()
{
	printf("task3\n");
}
void task2()
{
	printf("task2 starting\n");
	printf("task2 deleting task1\n");
	taskDelete(taskid1);
	printf("task2 deleting task3\n");
	taskDelete(taskid3);
	printf("task2 completed\n");
}
void task1()
{
	printf("task1 starting\n");
	printf("making task1 safe\n");
	taskSafe();
	printf("creating task2\n");
	taskid2=taskSpawn("task2",102,NULL,512,(void*)&task2,0,0,0,0,0,0,0,0,0,0);
	printf("making task1 unsafe\n");
	taskUnsafe();
	printf("task1 taking semaphore\n");
/*	semGive(semid1);*/
	semTake(semid1,WAIT_FOREVER);
	printf("task1 taken semaphore\n");
	printf("task1 completed\n");	
}
void root()
{
	taskid1=taskSpawn("task1",103,NULL,512,(void*)&task1,0,0,0,0,0,0,0,0,0,0);
	taskid3=taskSpawn("task3",104,NULL,512,(void*)&task3,0,0,0,0,0,0,0,0,0,0);
	semid1=semBCreate(SEM_Q_PRIORITY,SEM_EMPTY);
}