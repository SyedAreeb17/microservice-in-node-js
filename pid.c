nclude <stdio.h>

#include <stdlib.h>

#include <pthread.h>







#define MIN_PID 100

#define MAX_PID 1000



int size_of_thread;

int thread_number = 0;

pthread_mutex_t mutex;





struct pid_tab

{

    int pid;

    float bitmap;

}pidArr[1000];



int allocate_map(void)                                  //allocates bitmap values to the data structure

{

    int i,j;

    for(i = MIN_PID, j =0; i <= MAX_PID; i++, j++)

    {

        pidArr[j].pid = i;

        pidArr[j].bitmap = 0;

    }



    if(i == MAX_PID && j == MAX_PID)

    {

    return 1;

	}

    else

    {

	return -1;

	}

}



int allocate_pid(void)                                  //allocates a pid to the new process

{

	int i,j;

    for(i = MIN_PID, j =0; i <= MAX_PID; i++, j++)

    {

        if(pidArr[j].bitmap == 0)

        {

            pidArr[j].pid = i;

            pidArr[j].bitmap = 1;

            return i;

            break;

        }

    }



}



void release_pid(int rpid)                               //releases pid

{

	int i;

    for(i = 0; i <= MAX_PID; i++)

    {

        if(pidArr[i].pid == rpid)

        {

            pidArr[i].bitmap = 0;

        }

    }

}



