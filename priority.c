//priority preemptive scheduling algorithm 
#include<stdio.h>
struct priority
{
    int btime;
    int atime;
    int wtime;
    int ttime;
    int pri;
}p[10];

int main()
{
    int i,n,tottime=0,towtime=0;
    int t=0,count=0,sp,temp[10];
    float avg_ttime,avg_wtime;
    printf("PREEMPTIVE PRIORITY SCHDULING ALGORITHM -----\n");
    printf("ENTER THE NUMBER OF PROCESS : ");
    scanf("%d",&n);
    printf("ENTER THE ARRIVAL TIME,BURST TIME AND PRIORITY : ");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&p[i].atime,&p[i].btime,&p[i].pri);
        temp[i]=p[i].btime;
    }
    p[9].pri = 10000;

    for(t=0;count!=n;t++)
    {
        sp=9;
        for(i=0;i<n;i++)
        {

            if(p[i].pri<p[sp].pri && (p[i].atime <=t && p[i].btime>0))
            {
                sp=i;
            }
        }

        p[sp].btime = p[sp].btime-1;

        if(p[sp].btime ==0)
        {
            count++;
            p[sp].wtime = t+1 -p[sp].atime - temp[sp];
            p[sp].ttime = t+1 -p[sp].atime;
            tottime += p[sp].ttime;
            towtime += p[sp].wtime;
        }
    }
     printf("\nprocess\t wtime\t ttime\t");

    for(i=0;i<n;i++)
    {
        printf("\np%d\t %d\t %d\t",i+1,p[i].wtime,p[i].ttime);
        
    }

    avg_ttime = tottime/n;
    avg_wtime = towtime/n;

    printf("\nAVG TURN AROUND TIME :%.2f",(float)avg_ttime);
    printf("\nAVG WAITING TIME :%.2f",(float)avg_wtime);
    
}
