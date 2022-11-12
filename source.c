#include <stdio.h>
#include <math.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int *a, int l, int h) {
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (a[j] < a[h]) {
            i++;
            swap(a+i, a+j);
        }
    }

    swap(a+i+1, a+h);
    return i++;
}

void quickSort(int *a, int l, int h) {
    if (l < h) {
        int pi = partion(a, l, h);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
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

    quickSort(a, 0, n - 1);

    solve(a, n);

    return 0;
}