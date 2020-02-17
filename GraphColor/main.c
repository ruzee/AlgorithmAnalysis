#include<stdio.h>
#include"GraphColor.h"

int main(int argc,char* argv[])
{
    char ch;
    printf("Please select method:\n1:for non recurse\n2:for recurse method\nother:exit directly\n");
    ch=getchar();
    if(ch=='2')
        TestBacktrack();
    else if(ch=='1')
        TestGraphColor();

    return 0;
}
