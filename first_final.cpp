#include <stdio.h>
#include <stdlib.h>

int main() {
    const int MAX_SIZE = 100000;
    int* arr = (int*)malloc(MAX_SIZE * sizeof(int));
    int n = 0;
    int x;

    long long sum = 0;
    int minVal = 10001, maxVal = -1;

    printf("Введите числа (окончание ввода -1):\n");

    while (scanf("%d", &x) == 1 && x != -1) {
        if (x < 0 || x > 10000) continue;
        arr[n++] = x;
        sum += x;
        if (x < minVal) minVal = x;
        if (x > maxVal) maxVal = x;
    }

    printf("\nКоличество введённых чисел: %d\n", n);
    printf("Сумма чисел: %lld\n", sum);
    printf("Минимальное: %d\n", minVal);
    printf("Максимальное: %d\n", maxVal);
    printf("Память, занимаемая числами: %zu байт\n", (size_t)n * sizeof(int));

    free(arr);
    return 0;
}
