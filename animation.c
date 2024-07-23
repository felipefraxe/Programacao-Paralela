#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

volatile int FLAG_STOP = 0; 
volatile int SLEEP_DURATION = 1000000; // Start with 1 second in microseconds

void* animation(void *arg) {

    int piguim[25][30] = { 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,11,10,10, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 3, 4, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11,10,10,10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 6, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0,11, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };  


    for (int i = 0; i < 1000000; i++) {
        
        printf("\033[2J\033[H");
        printf("\r");
        for(int k=0; k < 25; k++){
            for(int j=0; j < 30; j++){
                if(piguim[k][(j+i)%30] == 0) printf(" ");
                if(piguim[k][(j+i)%30] == 1) printf("_");
                if(piguim[k][(j+i)%30] == 2) printf("(");
                if(piguim[k][(j+i)%30] == 3) printf("o");
                if(piguim[k][(j+i)%30] == 4) printf("`");
                if(piguim[k][(j+i)%30] == 5) printf("-");
                if(piguim[k][(j+i)%30] == 6) printf("/");
                if(piguim[k][(j+i)%30] == 7) printf("\\");
                if(piguim[k][(j+i)%30] == 8) printf("|");
                if(piguim[k][(j+i)%30] == 9) printf("^");
                if(piguim[k][(j+i)%30] == 10) printf("=");
                if(piguim[k][(j+i)%30] ==11) printf("<");
                if(piguim[k][(j+i)%30] == 15) printf("\n");
            }
            printf("\n");
    
        }

        printf("\nEnter 1 to stop, 2 to speed up: \n");
        
        fflush(stdout); 

        for (int k = 0; k < SLEEP_DURATION; k += 10000) { 
            if (FLAG_STOP == 1) return NULL; 
            usleep(10000);
        }
            
    }
    printf("\n");
    return NULL; 
}

void* stopAnimation(void* arg) {
    int command;
    while (1) {
        printf("\nEnter 1 to stop, 2 to speed up: \n");
        scanf("%d", &command);
        if (command == 1) {
            FLAG_STOP = 1;
            break;
        } else if (command == 2) {
            SLEEP_DURATION = SLEEP_DURATION > 10000 ? SLEEP_DURATION / 2 : 10000; 
        }
    }
    return NULL; 
}

int main(int argc, char* argv[]) {
    pthread_t threads[2];

    pthread_create(&threads[0], NULL, animation, NULL);
    pthread_create(&threads[1], NULL, stopAnimation, NULL);
    
    for(int i = 0; i < 2; i++)
        pthread_join(threads[i], NULL);

    return 0;
}
