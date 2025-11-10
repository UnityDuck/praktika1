#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

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
    vector<pair<int, int>> results; // (N, M(N))

    for (int N = 1; N <= LIMIT; N++) {
        int countP, countE, sumP, sumE;
        analyze(N, countP, countE, sumP, sumE);

        if (countP == countE && countP != 0) {
            int M = abs(sumP - sumE);
            results.push_back({N, M});
        }
    }

    sort(results.rbegin(), results.rend()); // сортировка по убыванию N

    cout << "Первые 5 наибольших чисел и их M(N):\n";
    for (int i = 0; i < 5 && i < results.size(); i++) {
        cout << results[i].first << " " << results[i].second << endl;
    }

    return 0;
}
