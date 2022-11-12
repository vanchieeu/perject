#include <stdio.h>
#include <math.h>

void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}
void cinArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

int minNumber(int a, int b) {
    if (a <= b)
        return a;
    else
        return b;
}

int absNumber(int a, int b) {
    return abs(a-b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    cinArray(a, n);

    quickSort(a, 0, n - 1);

    int min = 999999999;

    for (int i = 0; i < n; i++) 
        min = minNumber(min, absNumber(a[i], a[i+1]));

    printf("%d", min);

    return 0;
}