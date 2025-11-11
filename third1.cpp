#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Проверка на простое число
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

// Вычисление F(N)
int F(int N) {
    int sum = 0;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            if (isPrime(i)) sum += i;
            int j = N / i;
            if (j != i && isPrime(j) && j != N) sum += j;
        }
    }
    return sum;
}

int main() {
    const int LIMIT = 750000;
    const int MAX_RESULTS = 10000;
    int* N_values = (int*)malloc(MAX_RESULTS * sizeof(int));
    int* F_values = (int*)malloc(MAX_RESULTS * sizeof(int));
    int resultCount = 0;

    for (int N = 2; N < LIMIT; N++) {
        int f = F(N);
        if (f != 0 && f % 111 == 0) {
            if (resultCount < MAX_RESULTS) {
                N_values[resultCount] = N;
                F_values[resultCount] = f;
                resultCount++;
            }
        }
    }

    // Сортировка пузырьком по убыванию N
    for (int i = 0; i < resultCount - 1; i++) {
        for (int j = 0; j < resultCount - i - 1; j++) {
            if (N_values[j] < N_values[j + 1]) {
                int tempN = N_values[j];
                N_values[j] = N_values[j + 1];
                N_values[j + 1] = tempN;

                int tempF = F_values[j];
                F_values[j] = F_values[j + 1];
                F_values[j + 1] = tempF;
            }
        }
    }

    printf("Первые 5 чисел и их F(N):\n");
    for (int i = 0; i < 5 && i < resultCount; i++) {
        printf("%d %d\n", N_values[i], F_values[i]);
    }

    free(N_values);
    free(F_values);
    return 0;
}
