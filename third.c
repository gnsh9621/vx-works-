/*Create two tasks with different priorities.
 Task1 should delay for 5 sec and then task2 should delay for 10 sec continuously. 
Observe the sequence of execution of the task.*/
#include<stdio.h>
#include<taskLib.h>
int tid1,tid2;
void task2()
{
 while(1)
 {
 printf("in task 2\n");
 taskDelay(600);
 }

       
}
void task1()
{              
         
       while(1)
	{
	printf("In the task1\n");
	taskDelay(300);
	}
	
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


}