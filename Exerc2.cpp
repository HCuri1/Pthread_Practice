#include <iostream>
#include <pthread.h>

using namespace std;

int vetor[14]= {2423,4564,853,2243,65756,32,3455,244,346546,22,4564,2,435,457447};

float a1, a2;

pthread_t thread1, thread2;

void *firstPart (void *Arg){

    int partial=0;

    for (int i= 0; i<7; i++){

        partial+= vetor[i];

    }

    a1= float(partial/7.0);

    return 0;

}

void *secondPart (void *Arg){

    int partial=0;

    for (int i= 7; i<14; i++){

        partial+= vetor[i];

    }

    a2= float(partial/7.0);

    return 0;

}

int main(){

    pthread_create(&thread1, NULL, firstPart, NULL);
    pthread_create(&thread2, NULL, secondPart, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    cout<<"Average: "<<(a1+a2)/2.0;

    return 0;
}