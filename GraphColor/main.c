#include<stdio.h>
#include<stdlib.h>
#include"GraphColor.h"

int main(int argc,char* argv[])
{
    char ch;
    while(1)
    {
        printf("\nPlease select method:\n1:for non recurse\n2:for recurse method\nothers:exit directly\n");
        ch=getchar();
        //fflush(stdin);//no action for gcc but for vc compliler
        getchar();//flush input cache
        if(ch=='2')
            TestBacktrack();
        else if(ch=='1')
            TestGraphColor();
        else
            //printf("\nBye Bye!\n");
            break;
    }
    return 0;
}
