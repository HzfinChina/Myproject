#include <string.h>
#include <stdio.h>

void cmp_and_swap_ref(char * & p1, char * & p2)
{
    char * t = p1;
    printf("t:%s\n", t);
    printf("p1:%s\n", p1);
    printf("p2:%s\n", p2);
    p1 = p2;
    p2 = t;
}

int main()
{
    char c1[] = "xyz" ;
    char c2[] = "abc";
    int num [] = { 1,2,3,4};
    char *p1 = c1;
    char *p2 = c2;
    printf("&c1 :%p\n", &c1);
    printf("c1 address:%p\n", c1);
    printf("*(c1+1):%c\n",*(c1+1));
    printf("*((c1) + sizeof(char)):%c\n",*((c1) + sizeof(char)));
    printf("*(c1 + sizeof(char)):%c\n",*(c1 + sizeof(char)));
    printf("c1+1 address:%p\n", c1+1);
    printf("c1+2 address:%p\n", c1+2);
    printf("p1 address:%p\n", p1);
    printf("&p1 :%p\n\n\n", &p1);
    printf("&num, %p\n", &num);
    printf("num address%p \n", num);
    printf("*num:%d\n", *num);
    printf("*(num+1):%d\n", *(num+1));
    unsigned long int  pnum = (unsigned long int)num;
    printf("pnum: %lx ", pnum);
    printf("(int)(num):%lx", (unsigned long int )(num));
}
