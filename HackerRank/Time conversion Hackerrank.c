#include<stdio.h>
#include<string.h>
int main()
{
    int comp;
    char time[8];
    scanf("%s",&time);
    strrev(time);
    char s1[] = {"MP"};
    printf("%s\n", time);
    printf("%s", s1);
    comp = strncmp(time, s1, 2);
    printf("%d", comp);
    if(comp==0)
    {
    	strrev(time);
    	
    	printf()
	}
}
