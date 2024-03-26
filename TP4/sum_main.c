#include <stdio.h>
#include "sum.h"

int main () {
    int a, b;
    printf("Enter a number : ");
    scanf("%d", &a);
    printf("Enter another number : ");
    scanf("%d", &b);

    int result = add(a,b);
    printf("The sum of %d and %d is %d", a, b, result);
    return 0;


}

// pour le lancer il faut faire : 
// gcc -W sum.h mainSum.c sum.c -o a 
// ou
// gcc mainSum.c -o a -W sum.h sum.c
// sinon on appelle pas sum.c et ça marche pas 
// et il faut appeller le sum.h si on a un header lock
