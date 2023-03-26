#include<stdio.h>
int main()
{
    int n,m,i,j,k,y,ind=0;
    int alloc[20][20],max[20][20],aval[30],need[20][20];
    printf("BANKERS ALGORITHM -----\n");


    printf("ENTER THE NUMBER OF PROCESS :");
    scanf("%d",&n);

    printf("ENTER THE NUMBER OF RESOURCES :");
    scanf("%d",&m);

    printf("ENTER THE ALLOCATION MATRIX :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("ENTER THE MAXIMUM MATRIX :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("ENTER THE AVAILABLE MATRIX :\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&aval[i]);
    }

    
    printf("CALCULATING NEED MATRIX :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("PRINTING NEED MATRIX -----------------\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("\n%d\t",need[i][j]);
            printf("\n");
        }
    }
    int  f[n], ans[n];
    for (k = 0; k < n; k++)
    {
        f[k] = 0;
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > aval[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                    {
                        aval[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    int flag1 = 1;
    for (i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag1 = 0;
            printf("Not safe");
            break;
        }
    }
    if (flag1 == 1)
    {
        printf("Following is the SAFE seq\n");
        for (i = 0; i < n - 1; i++)
        {
            printf(" P%d->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }
return 0;

}