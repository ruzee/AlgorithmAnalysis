#include <stdio.h>
#include "GraphColor.h"

int OK(int n,int AdjacencyTable[][MAXSIZE],int *Color,int k)
{
    int i;
    for(i=0;i<n;i++)
        if(AdjacencyTable[k][i] && Color[i]==Color[k])
            return 0;
    return 1;
}

void outputColorResult(int n,int* color)
{
    static int cnt=0;
    int i ;
    printf("solution %d: ",++cnt);
    for(i = 0 ; i < n ; i++)
    {
        printf("%d ",color[i]);
    }
    printf("\n");
}

//recursion function
void backtrack(int n,int m,int AdjacencyTable[][MAXSIZE],int *Color,int k)
{
    static int cnt=0;
    if(k>=n)
        outputColorResult(n,Color);//output the solution
    else
    {
        for(int i=1;i<=m;i++)
        {
            Color[k]=i;
            if(OK(n,AdjacencyTable,Color,k))
            {
                printf("trial:%d node:%d  color:%d\n",++cnt,k,i);  //trace mark
                backtrack(n,m,AdjacencyTable,Color,k+1);
            }
            Color[k]=0;
        }
    }
}

void TestBacktrack()
{
    int n,m;//0..n-1 nodes,1..m colors
    int i,j;//for loop only
    int AdjacencyTable[MAXSIZE][MAXSIZE];
    int Color[MAXSIZE];
    FILE *file;

    file=fopen("./graphdata.txt","r");
    fscanf(file,"%d%d",&n,&m);

    //read the data from file
    for(i = 0; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            fscanf(file,"%d",&AdjacencyTable[i][j]);
        }
    }

    fclose(file);
    //start to color
    backtrack(n,m,AdjacencyTable,Color,0);
}
