#include <iostream>
#include <vector>

bool is_prime(int n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int F(int N) {
    std::vector<int> divisors;
    for (int d = 2; d * d <= N; d++) {
        if (N % d == 0) {
            if (is_prime(d) && d % 10 == 7 && d != N) {
                divisors.push_back(d);
            }
            int other = N / d;
            if (other != d && is_prime(other) && other % 10 == 7 && other != N) {
                divisors.push_back(other);
            }
        }
    }
    // Проверить само N на простоту и окончание на 7
    if (is_prime(N) && N % 10 == 7) {
        // но по условию не считая самого N, так что пропускаем
    }

    if (divisors.empty()) return 0;

    int sum = 0;
    for (int p : divisors) sum += p;
    return sum / divisors.size();
}

int main() {
    int count = 0;
    for (int N = 749999; N >= 2 && count < 5; N--) {
        int f_val = F(N);
        if (f_val != 0 && f_val % 111 == 0) {
            std::cout << N << " " << f_val << "\n";
            count++;
        }
    }
    return 0;
}
