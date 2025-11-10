#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100000; // запас
    int* arr = new int[MAX_SIZE];
    int n = 0;
    int x;

    long long sum = 0;
    int minVal = 10001, maxVal = -1;

    cout << "Введите числа (окончание ввода -1):" << endl;

    while (cin >> x && x != -1) {
        if (x < 0 || x > 10000) continue; // защита от некорректного ввода
        arr[n++] = x;
        sum += x;
        if (x < minVal) minVal = x;
        if (x > maxVal) maxVal = x;
    }

    cout << "\nКоличество введённых чисел: " << n << endl;
    cout << "Сумма чисел: " << sum << endl;
    cout << "Минимальное: " << minVal << endl;
    cout << "Максимальное: " << maxVal << endl;
    cout << "Память, занимаемая числами: " << n * sizeof(int) << " байт" << endl;

    delete[] arr;
    return 0;
}
