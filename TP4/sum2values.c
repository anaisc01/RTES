#include <stdio.h>

int main() {
    int a, b;
    printf("Enter a number : ");
    scanf("%d", &a);                        // scanf sert à attendre une entrée de la part de l'utilisateur
    printf("Enter another number : ");
    scanf("%d", &b);      
    printf("The sum of %d and %d is : %d ", a, b, a+b);
    return 0;

}