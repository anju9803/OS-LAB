//non preemptive sjf schduling
#include<stdio.h>
struct sjf
{
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

int main()
{
    int i,j,n,tottime=0,towtime=0;
    float avg_wtime,avg_ttime;
    printf("ENTER THE NUMBER OF PROCESS : ");
    scanf("%d",&n);
   
    for(i=0;i<n;i++)
    {
         printf("ENTER EACH PROCESS :");
        scanf("%d",&p[i].pid);
        printf("ENTER THE BURST TIME :");
        scanf("%d",&p[i].btime);
    }

    p[0].wtime=0;
    p[0].ttime=p[0].btime;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].btime > p[j+1].btime)
            {
                int temp;
                temp = p[j].btime;
                p[j].btime = p[j+1].btime;
                p[j+1].btime = temp;
            }
            
        }
    }

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
