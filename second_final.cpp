#include <iostream>
#include <cmath>
#include <vector>

// Функция факторизации: возвращает (Ω(N), сумма простых делителей с повторениями)
std::pair<int, int> prime_omega_and_sum(int n) {
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
    return {omega, sum_primes};
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

int main(int argc, char *argv[]) {
    int found = 0;
    for (int N = 100000001; found < 5; N++) {
        // Степень двойки в N
        int a = 0;
        int n_temp = N;
        while (n_temp % 2 == 0) {
            a++;
            n_temp /= 2;
        }
        int m = n_temp;

        if (a == 0) continue; // нет чётных делителей

        auto [omega, sum_primes] = prime_omega_and_sum(N);

        int tau_m = count_divisors(m);
        int even_div_count = a * tau_m;

        if (omega == even_div_count) {
            // Сумма чётных делителей
            int sum_even = ((1 << (a + 1)) - 2) * sum_divisors(m);
            int M = std::abs(sum_primes - sum_even);
            std::cout << N << " " << M << "\n";
            found++;
        }
    }
    return 0;
}
