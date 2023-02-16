#include <stdio.h>

int main() {

    int  top, num1, num2, 
    count, mod,stack[100];
    top=-1;
    count=0;

    printf("\nPlease enter a number : ");
    scanf("%d", &num1);

    num2 = num1;

    while (num1 != 0) {
    
        mod = num1 % 10;
        stack[top] = mod;
        num1 /= 10;
        top++;
    
    }

    num1 = num2;
    top--;

    while(num1 != 0) {

        mod = num1 % 10;

        if(mod == stack[top--]) {}
        else {
            count = 1;
        }

        num1 /= 10;

    }

    if(count == 1) {
        printf("\nThe number is not a palindrome\n");
    }
    else {
        printf("\nThe number  is a palindrome\n");
    }



    return 0;
}