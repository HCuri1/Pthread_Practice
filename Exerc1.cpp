#include <iostream>
#include <pthread.h>

using namespace std;

int vetor[14] = {33,5676,234,4567,243,7567,238,434,11,443,572,553,233,775};

int g1, g2;

pthread_t thread1, thread2;

void *greater1(void *Arg){

    g1= vetor[0];

    for (int i=0; i<7; i++){

        if (vetor[i]>g1){

            g1=vetor[i];

        }

    }

    return 0;
}

void *greater2(void *Arg){

    g2= vetor[7];

    for (int i=7; i<14; i++){

        if (vetor[i] > g2){

            g2 = vetor[i];

        }

    }

    return 0;
    
}

int main (){

    pthread_create(&thread1, NULL, greater1, NULL);
    pthread_create(&thread2, NULL, greater2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    if (g1>g2){

        cout<<"Greater: "<<g1<<endl;

    }

    else{

        cout<<"Greater: "<<g2<<endl;

    }
    

    return 0;
}