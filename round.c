#include<stdio.h>
struct round
{
    int pid;
    int btime;
    int atime;
    int wtime;
    int ttime;

}p[10];

int q[15],front = -1,rear =-1;
void insert (int p)
{
    if(front==-1)
    {
        front=0;
    }
    rear += 1;
    q[rear]  = p;
}

int delete ()
{
    int p;
    p = q[front];
    front += 1;
    return p;
}

void main()
{
    int n,i,exist[20]={0},tottime,towtime;
    float avg_ttime,avg_wtime;
    int temp[10],time=0,t,a;
    printf("ROUND ROBIN-----\n");
    printf("ENTER THE NUMBER OF PROCESS :");
    scanf("%d",&n);
    printf("ENTER THE ARRIVAL TIME AND BURST TIME :");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].atime,&p[i].btime);
        p[i].pid = i+1;
        temp[i]= p[i].btime;
    }

    printf("ENTER THE TIME QUANTUM :");
    scanf("%d",&t);

    insert(0);
    exist[0] =1;
    while(front<=rear)
    {
        a=delete();
        if(p[a].btime >=t)
        {
            p[a].btime -= t;
            time += t;
        }
        else
        {
           time+= p[a].btime ;
           p[a].btime =0;

        }

        for(i=1;i<n;i++)
        {
            if(exist[i]==0 && p[i].atime<=time)
            {
                insert(i);
                exist[i] = 1;
            }
        }
        if(p[a].btime ==0)
        {
            p[a].ttime = time - p[a].atime;
            p[a].wtime = p[a].ttime - temp[a];
        }
        else
        {
            insert(a);
        }
    }
    printf("process\t ttime\t wtime\t ");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t",p[i].pid,p[i].ttime,p[i].wtime);
    }

    
}

