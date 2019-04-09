#include <stdio.h>
#include <taskLib.h>
#include <semLib.h>
STATUS status1,status2,status3,status4;
int taskid1,taskid2;
SEM_ID semid;
void task2()
{
	printf("iam task 2 starting\n");
	printf("trying to delete task1\n");
	taskDelete(taskid1);
	printf("iam task 2 ending\n");
}
void task1()
{
	printf("iam task 1 starting\n");
	status1=semTake(semid,WAIT_FOREVER);
	taskDelay(300);
	printf("Delete not success iam task 1 ending\n");
}

void root()
{
	semid=semMCreate(SEM_Q_PRIORITY|SEM_DELETE_SAFE|SEM_INVERSION_SAFE);
	taskid1=taskSpawn("task1",102,NULL,512,(void*)&task1,0,0,0,0,0,0,0,0,0,0);
	taskid2=taskSpawn("task2",103,NULL,512,(void*)&task2,0,0,0,0,0,0,0,0,0,0);
}