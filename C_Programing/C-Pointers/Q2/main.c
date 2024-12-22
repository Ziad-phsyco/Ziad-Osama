//C program to print all the alphabit 

#include <stdio.h>

int main(){
    char alphabit[27];

    char *ptr;

    ptr = alphabit;

    for(int i = 0; i < 26; i++){
        *ptr = i + 'A';
        ptr++;    
    }
    ptr = alphabit;

    printf("The alphabits are: \n");
    for(int i=0;i<26;i++){
        printf(" %c ", *ptr);
        ptr++;
    }
    return 0;
}