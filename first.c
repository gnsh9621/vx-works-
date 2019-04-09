/*Create task1 with some priority.
 Now from task1 create other task (task2).
 Now that task2 sleeps for some time(100ms)
.Observe the execution sequence by looking at the 'printf' statements.*/
#include<stdio.h>
#include<taskLib.h>
int tid1,tid2;
void task2()
{
 printf("in task 2\n");
taskDelay(10);
printf("Out of Delay\n");
       
}
void task1()
{
	printf("In the task1\n");
	tid2=taskSpawn
    (
    "task2",      /* name of new task (stored at pStackBase) */
    105,  /* priority of new task */
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
void root()
{
 	printf("In the root\n");    
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


}