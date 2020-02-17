#ifndef GRAPHCOLOR_H_INCLUDED
#define GRAPHCOLOR_H_INCLUDED

#define MAXSIZE 100

//recursion function
int OK(int n,int AdjacencyTable[][MAXSIZE],int *Color,int k);
void outputColorResult(int n,int* color);
void backtrack(int n,int m,int AdjacencyTable[][MAXSIZE],int *Color,int k);
void TestBacktrack();

//non recursion function
int isOK(int k,int AdjacencyTable[MAXSIZE][MAXSIZE],int* color);
void printResult(int n,int* color);
void GraphColor(int n,int m,int AdjacencyTable[MAXSIZE][MAXSIZE],int* color);
void TestGraphColor();


#endif // GRAPHCOLOR_H_INCLUDED
