#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int csum;
int msum;
void *runner(void *pr);
int main(int argc,char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,argv[1]);
    msum = 0;
    for(int i =1;i <= atoi(argv[1]);i++){
        msum += i;
    }
    pthread_join(tid,NULL);
    printf("%d - %d = %d\n",csum,msum,csum - msum);
    return 0;
}
void *runner(void *pr){
    int a = atoi(pr) * 2;
    csum = 0;
    for(int i = 1;i < a;i++){
        csum +=i;
    }
    pthread_exit(0);
}