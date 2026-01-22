#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
int main(){
    int arr[30];
    int status;
    pid_t p1,p2;
    int final_sum_p1=0, final_sum_p2=0;
    srand(time(NULL));
    printf("Array initialized by parent...\n\n");
    for (int i=0;i<30;i++){
    arr[i]=(rand()%30)+1;
    if(i==14)
    printf("|");
    printf("%d",arr[i]);
    }
    printf("/n");
    p1 =fork();
    if(p1==0){
        int sum1=0;
        for (int i=0;i<15;i++)
        if(arr[i]%2==0){
        sum1 += arr[i];
        }
        sleep(1);
        exit(sum1);
    }
    waitpid(p1,&status,0);
    final_sum_p1=WEXITSTATUS(status);
    
    p2 =fork();
    if(p2==0){
        int sum2=0;
        for (int i=15;i<30;i++)
        if(arr[i]%2==0){
        sum2 +=arr[i];
        }
        exit(sum2);
    }
    waitpid(p2,&status,0);
    final_sum_p2=WEXITSTATUS(status);
    printf("\n total even sum of left side and right side are :%d and %d/n",final_sum_p1,final_sum_p2);
    return 0;

}