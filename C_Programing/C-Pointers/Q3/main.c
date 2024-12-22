//program to reverse string using pointers

#include <stdio.h>

int main()
{
    char str[100];
    char revstr[100];
    int i = -1 ;     //we start from -1 as there is an extra character which is null

    char *strptr = str;
    char *revptr = revstr;
    printf("Input a string: ");
    scanf("%s", str);

    while(*strptr){
        strptr++;
        i++;
    }
    while (i>=0){
        strptr--;
        *revptr = *strptr;
        revptr++;
        --i;
    }
    *revptr = '\0';
    printf("Reverse of the string is: %s \n", revstr);
    return 0;
}


