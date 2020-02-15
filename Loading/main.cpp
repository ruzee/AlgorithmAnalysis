/*
装载问题的回溯算法
*/

#include<iostream>
#include<string.h> //for memset,memcpy

using namespace std;
int cmpfunc(const void * a,  const void * b)
{
    return -((*(int*)a - *(int*)b));
}

//calculate the total loading(first i loading) in the sheep
//so as to check if xi can be loaded onto sheep one
int canLoadi(int *W,int *x,int i)
{
    int k,sum;
    sum=0;
    for(k=0;k<i;k++) //check first i-1 containers loading
        sum+=W[k]*x[k];
    return sum+W[i]; //loading i container onto sheep

}

int Loading(int W[], int n,int *x, int c)
{
    int B = c, best = c, i = 0;
    int *xx = new int[n];
    memset(xx, 0, n*sizeof(int));
    qsort(W, n, sizeof(int), cmpfunc);
L3:
    while (i < n)
    {
        if(canLoadi(W,xx,i)<=c)//check if exceed the capcity of sheep under load i
        {
            B -= W[i];
            xx[i] = 1;
        }
        else
            xx[i] = 0;
        i++;
    }
    if (B < best)
    {
        memcpy((void*)x, (void*)xx, sizeof(int)*n);//记录解
        best = B;
    }
    //回溯
    i--;
    while (i > 0 && xx[i] == 0)
        i--;
    if (xx[i] == 1)//回溯
    {
        xx[i] = 0;
        B += W[i];
        i++;
    }
    if (i == 0)
    {
        delete[] xx;
        return best;
    }
    else
        goto L3;
}
//weight fo Sheep on Loading
int SheepOneLoad(int *W,int *x,int n)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
        sum+=W[i]*x[i];
    return sum;
}

void TestLoading()
{
    int c1 = 152;//sheep one capacity
    int c2 = 130;

    int W[] = {40, 90, 80, 10,  30, 20, 12 };//container weight
    int n=sizeof(W)/sizeof(*W);//number of containers
    int *x;
    x = new int[n];
    memset(x, 0, n*sizeof(int));

    int gap = Loading(W, n, x, c1);
    cout << "c=" << c1 << "\tgap=" << gap << endl;
    for (int i = 0; i < n; i++)
        cout << W[i] << '\t';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << x[i] << '\t';
    cout << endl;

    cout<<"\nthe first sheep Capcity: "<<c1<<endl;
    cout<<"the first sheep load: "<<SheepOneLoad(W,x,n)<<endl;
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=W[i];

    cout<<"==========================="<<endl;

    int SheepTwoLoad=sum-SheepOneLoad(W,x,n);
    cout<<"the second sheep Capcity: "<<c2<<endl;
    cout<<"the second sheep load: "<<SheepTwoLoad<<endl;

    if(SheepTwoLoad<=c2)
        cout<<"Load OK"<<endl;
    else
        cout<<"Can not Load"<<endl;
    delete[] x;
}

int main()
{
    TestLoading();
    return 0;
}
