#include <stdio.h>
int CalcSum(int n);
void main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Sum = %d", CalcSum(n));
}

int CalcSum(int n) {
    if (n != 0)
        return n + CalcSum(n - 1);
    else
        return n;
}













