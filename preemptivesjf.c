//preemptive sjf scheduling------
#include<stdio.h>
struct sjf1
{
    int btime;
    int atime;
    int ttime;
    int wtime;

}p[10];

int main()
{
    int i,n,sp,tottime=0,temp[10],towtime=0;
    int t=0,count=0;
    float avg_ttime,avg_wtime;
    printf("SJF PREEMPTIVE SCHDULING ALGORITHM------\n");
    printf("ENTER NUMBER OF PROCESS :");
    scanf("%d",&n);
    printf("ENTER THE ARRIVAL TIME AND BURST TIME : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].atime,&p[i].btime);
        temp[i]=p[i].btime;
    }

    p[9].btime=10000;

    for(t=0;count!=n;t++)
    {
        sp=9;
        for(i=0;i<n;i++)
        {
            if(p[i].btime<p[sp].btime && (p[i].atime <=t && p[i].btime>0))
            {
                sp = i;
            }
        }
        p[sp].btime = p[sp].btime-1;

        if(p[sp].btime==0)
        {
            count++;
            p[sp].wtime = t+1 - p[sp].atime - temp[sp];
            p[sp].ttime = t+1 - p[sp].atime;
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

    printf("AVG TURN AROUND TIME :%.2f",(float)avg_ttime);
    printf("AVG WAITING TIME :%.2f",(float)avg_wtime);

    

}
