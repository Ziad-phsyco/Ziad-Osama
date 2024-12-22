//C program to print an array in reverse order
#include <stdio.h>
int main(){
    int x, i , arr[15];
    int *ptr = arr;

    printf("Enter any number of elements to store max(15)\n");

    scanf("%d", &x);

    for(i = 0; i < x; i++){
        printf("Element - %d: ", i+1);
        scanf("%d", ptr);
        ptr++;
    }
    ptr = &arr[x-1];
    printf("The elements in reverse order: \n");
    for (i = x; i > 0; i--){
        printf("Elemenet - %d = %d \n", i, *ptr);
        ptr--;
    }
    
    return 0;
}