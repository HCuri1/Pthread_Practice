#include <iostream>
#include <pthread.h>

using namespace std;

pthread_t thread1, thread2;

pthread_mutex_t mutex;

int vetor[14]= {2423,4564,853,2243,65756,32,3455,244,346546,22,4564,2,435,457447};

int result=0;

void *part1 (void *arg){

    int temp;

    for(int i=0; i<7; i++){

        pthread_mutex_lock(&mutex);
        temp= result;
        temp+=vetor[i];
        result=temp;
        pthread_mutex_unlock(&mutex);

    }

    pthread_exit(0);

}

void *part2 (void *arg){

    int temp;

    for(int i=7; i<14; i++){

        pthread_mutex_lock(&mutex);
        temp= result;
        temp+=vetor[i];
        result=temp;
        pthread_mutex_unlock(&mutex);

    }

    pthread_exit(0);

}

int main (){

    pthread_create(&thread1, NULL, part1, NULL);
    pthread_create(&thread2, NULL, part2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    cout<<"Result: "<<result;

    return 0;
}