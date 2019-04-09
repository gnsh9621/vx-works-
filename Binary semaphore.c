#include <stdio.h>
#include <taskLib.h>
#include <semLib.h>
STATUS status1,status2,status3,status4;
SEM_ID semid;
void task3()
{
	printf("I am task 3 starting\n");
	status3=semTake(semid,WAIT_FOREVER);
	printf("Semaphore taking task 3 : %d\n",status1); /* 0=SUCCESS: -1=FAILURE */
/*	taskDelay(300);*/ /* 5 SECONDS DELAY */
	printf("iam task 3 ending\n");
	status3=semGive(semid);
	printf("Semaphore releasing by task 3 : %d\n",status3);
}
void task2()
{
	printf("iam task 2 starting\n");
	printf("Going to release semaphore by task 2\n");
	status2=semGive(semid);
	printf("Semaphore releasing by task 2  : %d\n",status2);
	printf("iam task 2 ending\n");
	printf("Going to release semaphore by task 2\n");
	status4=semGive(semid);
	printf("Semaphore releasing by task 2 : %d\n",status4);
}
void task1()
{
	int taskid3;
	printf("iam task 1 starting\n");
	status1=semTake(semid,WAIT_FOREVER); /* TASK WAIT UNTIL SEMGIVE IS USED TO TAKE THE KEY */
/*	status1=semTake(semid,NO_WAIT);*/ /* TASK TAKE THE KEY ONLY IF THE KEY IS AVAILABLE AT THAT INSTANT */
	printf("Semaphore taking task 2 : %d\n",status1); /* 0=SUCCESS: -1=FAILURE */
	taskid3=taskSpawn("task3",100,NULL,512,(void*)&task3,0,0,0,0,0,0,0,0,0,0);
/*	taskDelay(300);*/ /* 5 SECONDS DELAY */
	printf("iam task 1 ending\n");
}

void root()
{
	int taskid1,taskid2;
	semid=semBCreate(SEM_Q_PRIORITY,SEM_EMPTY); /* EMPTY = KEY NOT AVAILABLE (only after semGive key will be available,used for synchronization) */
/*	semid=semBCreate(SEM_Q_PRIORITY,SEM_FULL);*/ /* FULL = KEY AVAILABLE (can be used directly) */
	taskid1=taskSpawn("task1",102,NULL,512,(void*)&task1,0,0,0,0,0,0,0,0,0,0);
	printf("task 1 id = %d\n",taskid1);
	taskid2=taskSpawn("task2",103,NULL,512,(void*)&task2,0,0,0,0,0,0,0,0,0,0);
	printf("task 2 id = %d\n",taskid2);
}