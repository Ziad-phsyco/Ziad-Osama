#include <stdio.h>

int main(){
    int* ab;
    int m;
    m = 29;
    printf("Address of m = %p\n", &m);
    printf("value of m = %d\n",m);


    ab = &m;
    printf("Now av is assigned with the adress of m. \n");
    printf("Address of pointer ab = %p\n", ab);
    printf("Content of pointer ab = %d\n", *ab);

    m = 34;
    printf("Now the value of m is assigned to 34 now. \n");
    printf("Address of pointer ab : %p \n", ab);
    printf("Content of pointer ab : %d\n", *ab);

    *ab = 7;
    printf("The pointer variable ab is assigned with the value 7 now.\n");
    printf("Address of m : %p\n", &m);
    printf("Value of m : %d\n", m);


    return 0;
}