#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int S, N;
    cin >> S >> N;

    int a[1000];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a, a + N);

    int sum = 0;
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (sum + a[i] <= S) {
            sum += a[i];
            k++;
        } else {
            break;
        }
    }

    int maxFile = a[k - 1];
    for (int j = k; j < N; j++) {
        if (sum - a[k - 1] + a[j] <= S) {
            maxFile = a[j];
        } else {
            break;
        }
    }

    cout << k << " " << maxFile << endl;

    return 0;
}

