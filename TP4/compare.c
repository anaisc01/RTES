#include <stdio.h>


int compare(int a, int b){
    if (a > b)
    return a;
    else if (b > a)
    return b;
    else
    return  a, b;


}


int main(){
    int a, b;
    printf("Enter a number : ");
    scanf("%d", &a);
    printf("Enter another number : ");
    scanf("%d", &b);

    int result = compare(a,b);
    printf("The largest number between  %d and %d is %d", a, b, result);
    return 0;
}