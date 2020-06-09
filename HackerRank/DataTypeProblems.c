#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int a;
    double b;
    char s1[100], s2;
    scanf("%d", &a);
    scanf("%f", &b);
    scanf("%s", s1);
    printf("%d \n", i+a);
    printf("%.2f\n", d+b);
     strcat(s, s1);
     printf("%s \n", s);
    return 0;
}
