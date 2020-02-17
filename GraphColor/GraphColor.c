#include <stdio.h>

const int MAXSIZE = 100;

//check whether there is conflict between the node k and its adjacent nodes
int isOK(int k,int AdjacencyTable[MAXSIZE][MAXSIZE],int* color)
{
    int i ;
    for(i = 0 ; i < k ; i++)
    {

        if(AdjacencyTable[i][k] && color[i] == color[k])
        {
            return 0;
        }
    }
    return 1;
}


void printResult(int n,int* color)
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

void GraphColor(int n,int m,int AdjacencyTable[MAXSIZE][MAXSIZE],int* color)
{
    int k = 0;//the depth of search tree
    static int cnt=1;//number of trial

    while(k >= 0)//k,the depth of search tree
    {

        color[k]++;//the current color is not ok,use the next color
        //check whether the selected color is ok
        while(color[k] <= m && !isOK(k,AdjacencyTable,color))
        {
            color[k]++;
        }

        //printf("trial:%d node:%d color:%d\n",cnt++,k,color[k]);

        if(color[k] <= m)//the color of node k if ok,
        {
            //and traverse to the leaf node,found a color solution
            if(k == n-1)
            {
                printResult(n,color);//output the color solution
                color[k]=0;//clear the color of current node k
                k--;//trace back the parent node
            }
            else
            {
                k++;//continue the next node
            }
        }
        else//All the color has been tried,but no color can be ok
        {
            //clear the color of current node k
            color[k] = 0;
            //trace back the parent node,when k=-1,jump out of while loop
            k--;
        }
    }
}

void TestGraphColor()
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

    //initial the color table
    //initial the color of nodes,0 represent no color
    //color[i]=1,2,...,m,color value
    //array index i represent the node number
    for(i = 0 ; i < n ; i++)
    {
        Color[i] = 0;
    }

    //start to color
    GraphColor(n,m,AdjacencyTable,Color);
}

int main(int argc,char* argv[])
{
    TestGraphColor();
    return 0;
}
