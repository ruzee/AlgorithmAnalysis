#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 4
#define NAN N+1

int isEmpty(int *S);
void Backtrack(int n);
void outputSolution(int *x);
void calcSk(int *S,int *x,int k);

int main()
{
    Backtrack(N);
    return 0;
}

//check whether a line in board is empty
//array s has N elements
//if all elements in S >N,return -1, represents no possible value
//else return the first index,which value < N

int isEmpty(int *s)
{
    int i;
    for(i=0;i<N;i++)
        if(s[i] != NAN)
            return i;
    return -1;
}

void outputSolution(int *x)
{
    static int cnt=1;
    int i;
    printf("the %dth solution: ",cnt++);
    for(i=0;i<N;i++)
        printf("%d  ",x[i]);
    printf("\n");
}

//array x[1..k-1] is ok,calculate the possible value of S[k]
void calcSk(int *s,int *x,int k)
{
    int i,j;

    for(i=0;i<N;i++)
        s[i]=i;
    //check conflict between x[i] and x[k]
    //story the kth possible value into S[k]
    for(i=0;i<k;i++)//row num
        for(j=0;j<N;j++)//col num
            if(abs(i-k)==abs(x[i]-j) || x[i]==j)
                s[j]=NAN;
            else if(s[j]!=NAN)
                s[j]=j;
}

void Backtrack(int n)
{
    int k,i,m;
    int x[N];//solution vectors
    int S[N][N];//posible values

    k=0;
    for(i=0;i<N;i++)
        S[0][i]=i;

L4:
    while((m=isEmpty(S[k]))!=-1)  //S[k] not empty
    {
        x[k]=m;
        S[k][m]=NAN;
        if(k<N-1)
        {
            k++;
            calcSk(S[k],x,k);//jisuan S[k]
        }
        else
            outputSolution(x);//output solution vectors
    }

    // traceback:check whether there is another solution
    if(k>0)
    {
        k--;
        goto L4;
    }
}
