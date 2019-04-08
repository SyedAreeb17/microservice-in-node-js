

void * Multi_Thread(void * v)                          //function called by the created thread

{

    int rpid = allocate_pid();       //allocates a pid

	while (thread_number < size_of_thread)

    {

        pthread_mutex_lock(&mutex);     //mutex lock occurs

        if (thread_number >= size_of_thread)

        {

            pthread_mutex_unlock(&mutex);

            break;

        }

        thread_number++;                    //threadVar increments at least once

        //sleep(100);

        printf("\n\t###############################################");

        printf("\n\t##   Thread %d    ##   Succesfully Created   ##",thread_number);

        pthread_mutex_unlock(&mutex);      //mutex now unlocked

    }

    //sleep(5);

    release_pid(rpid);           //pid released



}



int main()

{

    int i =0;

    printf("\n\tEnter How Many Number of Threads You Want : ");

    scanf("%d",&size_of_thread);

    pthread_t thread[size_of_thread];



	printf("\n\t###############################################");

	printf("\n\t##                                           ##");

	printf("\n\t##          Creating %d Threads              ##",size_of_thread);

	printf("\n\t##                                           ##");

	printf("\n\t###############################################");



//   sleep(1000);        //delay only so that the above can be read in output screen before execution of the rest of the code



    for(i = 0; i < size_of_thread; i++)

    {

        pthread_mutex_init(&mutex, NULL);

        pthread_create(&thread[i], NULL, Multi_Thread, NULL);

        Multi_Thread(NULL);

    }



    for(i = 0; i < size_of_thread; i++)

    {

        pthread_join(thread[i], NULL);

        pthread_mutex_destroy(&mutex);

    }

	printf("\n\t###############################################");

    return 0;

}
