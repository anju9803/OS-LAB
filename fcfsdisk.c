#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,rq[50],initial=0,total_head_movement=0;
    printf("ENTER THE NUMBER OF REQUEST :");
    scanf("%d",&n);
    printf("ENTER THE REQUESTS :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    printf("ENTER THE INITIAL POSITION :");
    scanf("%d",&initial);

    for(i=0;i<n;i++)
    {
        total_head_movement += abs(rq[i]-initial);
        initial = rq[i];
    }
    printf("TOTAL HEAD MOVEMENT :%d",total_head_movement);
    return 0;
}