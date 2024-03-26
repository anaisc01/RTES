#include <stdio.h>


int main () {
    int a;
    printf("Enter a number : ");
    scanf("%d", &a);


    printf("The value is %d and the mermory adress is %p", a, &a);      // le %p et &a permettent de print l'adresse
    return 0;


}