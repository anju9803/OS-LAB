//calculate avg turn around time and avg waiting time
#include<stdio.h>
struct fcfs

{
    int pid;
    int btime;
    int ttime;
    int wtime;
}p[10];

int main()
{
    int n,i,tottime=0,towtime=0;
    float avg_ttime,avg_wtime;
    printf("FCFS SCHEDULING--------\n");
    printf("ENTER THE NUMBER OF PROCESS : ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        p[i].pid =1;
        printf("ENTER PROCESS ID p%d :",i+1);
        scanf("%d",&p[i].pid);
        printf("ENTER THE BURST_TIME FOR %d PROCESS : ",i+1);
        scanf("%d",&p[i].btime);
    }
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;

    for(i=0;i<n;i++)
    {
        p[i].wtime = p[i-1].wtime + p[i-1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        tottime += p[i].ttime;
        towtime += p[i].wtime;
    }

    avg_ttime = tottime/n;
    avg_wtime = towtime/n;
    printf("\nAVERGAE TURN AROUND TIME :%.2f",(float)avg_ttime);
    printf("\nAVERAGE WAITING TIME : %.2f",(float)avg_wtime);
}
