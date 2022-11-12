#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void TwoNumbers(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void arangeTwoNumbers(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (*(a+i) < *(a+j))    
            TwoNumbers(a+i, a+j);
}

void cinArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int minNumber(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int absNumber(int a, int b) {
    return abs(a-b);
}

void solve(int *a, int n) {
    int min = abs(a[0] - a[1]);

    for (int i = 0; i < n - 1; i++) 
        min = minNumber(min, absNumber(a[i], a[i+1]));

    printf("%d", min);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    cinArray(a, n);

    arangeTwoNumbers(a, n);

    solve(a, n);

    return 0;
}