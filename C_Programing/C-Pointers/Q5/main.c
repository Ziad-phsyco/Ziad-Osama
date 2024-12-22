// C program to show a pointer to an array which contents are pointer to structure

#include <stdio.h>

struct Semployee{
    char *empName;
    int empID;
};

int main(){
    struct Semployee emp1={"Ziad",1001}, emp2={"Osama",1002}, emp3={"Mohamed",1003};
    struct Semployee(*arr[]) = {&emp1, &emp2, &emp3};
    struct Semployee(*(*ptr)[3]) = &arr;

    printf("Employee Name: %s \n", (*(*ptr+1))->empName);
    printf("Employee ID: %d \n", (*(*ptr+1))->empID);
    return 0;

}