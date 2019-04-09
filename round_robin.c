/*Round robin.*/
#include<stdio.h>
#include<taskLib.h>
#include<kernelLib.h>
int tid1,tid2;
void task2()
{
 while(1)
{
 printf("task 2\n");
 taskDelay(30);
}
       
}
void task1()
{
        while(1)
{
	printf("task1\n");
	taskDelay(30);
}
}
void root()
{
 	printf("In the root\n"); 
       kernelTimeSlice(60);   
	tid1=taskSpawn
    (
    "task1",      /* name of new task (stored at pStackBase) */
    110,  /* priority of new task */
    0,   /* task option word */
    256, /* size (bytes) of stack needed plus name */
    task1,   /* entry point of new task */
    0,      /* 1st of 10 req'd task args to pass to func */
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
    );
	tid2=taskSpawn
    (
    "task2",      /* name of new task (stored at pStackBase) */
    110,  /* priority of new task */
    0,   /* task option word */
    256, /* size (bytes) of stack needed plus name */
    task2,   /* entry point of new task */
    0,      /* 1st of 10 req'd task args to pass to func */
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
    );
	printf("the task2 in sleeping\n");


}