#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int S, N;
    scanf("%d %d", &S, &N);

    int a[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, N, sizeof(int), compare);

    int sum = 0;
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (sum + a[i] <= S) {
            sum += a[i];
            k++;
        } else {
            break;
        }
    }

    int maxFile = a[k - 1];
    for (int j = k; j < N; j++) {
        if (sum - a[k - 1] + a[j] <= S) {
            maxFile = a[j];
        } else {
            break;
        }
    }

    printf("%d %d\n", k, maxFile);

    return 0;
}
