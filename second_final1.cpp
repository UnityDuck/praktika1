#include <stdio.h>
#include <stdlib.h>

// Функция факторизации: возвращает (Ω(N), сумма простых делителей с повторениями)
int prime_omega_and_sum(int n, int* sum_primes_out) {
    int omega = 0;
    int sum_primes = 0;
    int temp = n;
    for (int i = 2; i * i <= temp; i++) {
        while (temp % i == 0) {
            omega++;
            sum_primes += i;
            temp /= i;
        }
    }
    if (temp > 1) {
        omega++;
        sum_primes += temp;
    }
    *sum_primes_out = sum_primes;
    return omega;
}

// Количество делителей нечётного числа m
int count_divisors(int m) {
    int cnt = 1;
    int temp = m;
    for (int i = 3; i * i <= temp; i += 2) {
        int exp = 0;
        while (temp % i == 0) {
            exp++;
            temp /= i;
        }
        cnt *= (exp + 1);
    }
    if (temp > 1) cnt *= 2;
    return cnt;
}

// Сумма делителей нечётного числа m
int sum_divisors(int m) {
    int sum = 1;
    int temp = m;
    for (int i = 3; i * i <= temp; i += 2) {
        int factor = 1;
        int power = 1;
        while (temp % i == 0) {
            power *= i;
            factor += power;
            temp /= i;
        }
        sum *= factor;
    }
    if (temp > 1) sum *= (1 + temp);
    return sum;
}

int main() {
    int found = 0;
    for (long long N = 100000001; found < 5; N++) {
        // Степень двойки в N
        int a = 0;
        long long n_temp = N;
        while (n_temp % 2 == 0) {
            a++;
            n_temp /= 2;
        }
        int m = (int)n_temp;

        if (a == 0) continue; // нет чётных делителей

        int sum_primes;
        int omega = prime_omega_and_sum((int)N, &sum_primes);

        int tau_m = count_divisors(m);
        int even_div_count = a * tau_m;

        if (omega == even_div_count) {
            // Сумма чётных делителей
            int power_of_2 = 1;
            for (int i = 0; i <= a; i++) {
                power_of_2 *= 2;
            }
            int sum_even_factor = power_of_2 - 2; // (2^(a+1) - 2)
            int sum_even = sum_even_factor * sum_divisors(m);
            int M = abs(sum_primes - sum_even);
            printf("%lld %d\n", N, M);
            found++;
        }
    }
    return 0;
}

