#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Проверка на простоту
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

// Функция для подсчёта P(N), E(N) и количества
void analyze(int N, int &countP, int &countE, int &sumP, int &sumE) {
    countP = countE = sumP = sumE = 0;

    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            int j = N / i;

            // i — делитель
            if (isPrime(i)) { sumP += i; countP++; }
            if (i % 2 == 0) { sumE += i; countE++; }

            // j — второй делитель, если не совпадает
            if (j != i) {
                if (isPrime(j)) { sumP += j; countP++; }
                if (j % 2 == 0) { sumE += j; countE++; }
            }
        }
    }
}

int main() {
    const int LIMIT = 1000000;
    const int MAX_RESULTS = 10000; // ограничим количество результатов
    int* N_values = (int*)malloc(MAX_RESULTS * sizeof(int));
    int* M_values = (int*)malloc(MAX_RESULTS * sizeof(int));
    int resultCount = 0;

    for (int N = 1; N <= LIMIT; N++) {
        int countP, countE, sumP, sumE;
        analyze(N, countP, countE, sumP, sumE);

        if (countP == countE && countP != 0) {
            int M = abs(sumP - sumE);
            if (resultCount < MAX_RESULTS) {
                N_values[resultCount] = N;
                M_values[resultCount] = M;
                resultCount++;
            }
        }
    }

    // Сортировка пузырьком по убыванию N
    for (int i = 0; i < resultCount - 1; i++) {
        for (int j = 0; j < resultCount - i - 1; j++) {
            if (N_values[j] < N_values[j + 1]) {
                // меняем N
                int tempN = N_values[j];
                N_values[j] = N_values[j + 1];
                N_values[j + 1] = tempN;
                // меняем M
                int tempM = M_values[j];
                M_values[j] = M_values[j + 1];
                M_values[j + 1] = tempM;
            }
        }
    }

    printf("Первые 5 наибольших чисел и их M(N):\n");
    for (int i = 0; i < 5 && i < resultCount; i++) {
        printf("%d %d\n", N_values[i], M_values[i]);
    }

    free(N_values);
    free(M_values);
    return 0;
}
