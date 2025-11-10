#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

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
    vector<pair<int, int>> results; // (N, F(N))

    for (int N = 2; N < LIMIT; N++) {
        int f = F(N);
        if (f != 0 && f % 111 == 0)
            results.push_back({N, f});
    }

    sort(results.rbegin(), results.rend()); // по убыванию N

    cout << "Первые 5 чисел и их F(N):\n";
    for (int i = 0; i < 5 && i < results.size(); i++) {
        cout << results[i].first << " " << results[i].second << endl;
    }

    return 0;
}
