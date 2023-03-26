#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,size,rq[20],initial=0,move,tohead=0;
    int i,j;
    printf("SCAN DISK SCHEDULING -----------\n");
    printf("ENTER THE NUMBER OF REQUEST :");
    scanf("%d",&n);
    printf("ENTER THE REQUESTS :\n");

    for(i=0;i<n;i++)
    {
    scanf("%d",&rq[i]);
    }
    printf("ENTER THE INITIAL HEAD : ");
    scanf("%d",&initial);
    printf("ENTER WHETHER HIGH OR LOW (press 1 for high 0 for low)!:");
    scanf("%d",&move);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(rq[j]<rq[j+1])
            {
                int temp;
                temp = rq[j];
                rq[j] = rq[j+1];
                rq[j+1] = temp;
            }
        }
    }
    int index;
    {
        for(i=0;i<n;i++)
        {
            if(initial<rq[i])
            {
                index=i;
                break;
            }
        }
    }
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            tohead+=abs(rq[i]-initial);
            initial = rq[i];
        }

        tohead+=abs(size-rq[i-1]-1);
        initial = size-1;

        for(i=index-1;i>=0;i--)
        {
            tohead+=abs(rq[i]-initial);
            initial = rq[i];
        }
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            tohead+=abs(rq[i]-initial);
            initial =rq[i];
        }
        tohead += abs(rq[i+1]-0);
        initial=0;

        for(i=index;i<n;i++)
        {
            tohead+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("TOTAL HEAD MOVEMENT :%d",tohead);
    return 0;

}


