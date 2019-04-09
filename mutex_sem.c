
#include<stdio.h>
#include<taskLib.h>
#include<msgQLib.h>
#include<semLib.h>
 int tid1,tid2,tid3,tid4;
SEM_ID s;
void fTask()
{
int i;
for(i=0;i<10;i++)
printf("Hi, in  task\n");


}
void tTask()
{
int i;
for(i=0;i<10;i++)
printf("Hi, in medium priority task\n");


}

void sTask()
{
printf("In higher priority task\n");
tid3=taskSpawn("task",105,0,512,(void*)tTask,0,0,0,0,0,0,0,0,0,0);

printf("created a medium priority task and asking for sem\n");

semTake
    (
    s,  /* semaphore ID to take */
    WAIT_FOREVER /* timeout in ticks */
    );
printf("giving the semaphore\n");

 semGive
    (
    s /* semaphore ID to give */
    );


}

void firstTask()
{
semTake
    (
    s,  /* semaphore ID to take */
    WAIT_FOREVER /* timeout in ticks */
    );
printf("In low priority task\n");

tid2=taskSpawn("task",100,0,512,(void*)sTask,0,0,0,0,0,0,0,0,0,0);
printf("giving the semaphore to higher priority\n");

 semGive
    (
    s /* semaphore ID to give */
    );
printf("\nend of the task\n");
}






void root()
{
 
s= semMCreate
    (
    SEM_Q_PRIORITY /* mutex semaphore options */
    );
tid1=taskSpawn("task1",110,0,512,(void*)firstTask,0,0,0,0,0,0,0,0,0,0);
tid4=taskSpawn("task",104,0,512,(void*)fTask,0,0,0,0,0,0,0,0,0,0);

}