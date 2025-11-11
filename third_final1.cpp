#include <stdio.h>
#include <stdlib.h>

bool is_prime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int F(int N) {
    const int MAX_DIVISORS = 64; // ограничим количество делителей
    int* divisors = (int*)malloc(MAX_DIVISORS * sizeof(int));
    int count = 0;

    for (int d = 2; d * d <= N; d++) {
        if (N % d == 0) {
            if (is_prime(d) && d % 10 == 7 && d != N) {
                if (count < MAX_DIVISORS) {
                    divisors[count] = d;
                    count++;
                }
            }
            int other = N / d;
            if (other != d && is_prime(other) && other % 10 == 7 && other != N) {
                if (count < MAX_DIVISORS) {
                    divisors[count] = other;
                    count++;
                }
            }
        }
    }

    if (count == 0) {
        free(divisors);
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += divisors[i];
    }
    int avg = sum / count;

    free(divisors);
    return avg;
}

int main() {
    int count = 0;
    for (int N = 749999; N >= 2 && count < 5; N--) {
        int f_val = F(N);
        if (f_val != 0 && f_val % 111 == 0) {
            printf("%d %d\n", N, f_val);
            count++;
        }
    }
    return 0;
}
