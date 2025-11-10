#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct FileInfo {
    char user[50];
    char filename[100];
    int size;
};

int main() {
    const int MAX = 1000;
    FileInfo files[MAX];
    int n = 0;

    ifstream fin("input.txt");
    if (!fin) {
        cout << "Не удалось открыть файл input.txt\n";
        return 1;
    }

    // Считывание данных
    while (fin >> files[n].user >> files[n].filename >> files[n].size) {
        n++;
        if (n >= MAX) break;
    }
    fin.close();

    // Подсчёт общего размера по пользователям
    char users[MAX][50];
    int totalSize[MAX];
    int userCount = 0;

    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < userCount; j++) {
            if (strcmp(users[j], files[i].user) == 0) {
                idx = j;
                break;
            }
        }

        if (idx == -1) { // новый пользователь
            strcpy(users[userCount], files[i].user);
            totalSize[userCount] = files[i].size;
            userCount++;
        } else {
            totalSize[idx] += files[i].size;
        }
    }

    // Находим пользователя с максимальным объёмом
    int maxIdx = 0;
    for (int i = 1; i < userCount; i++) {
        if (totalSize[i] > totalSize[maxIdx])
            maxIdx = i;
    }

    cout << "Пользователь с наибольшим объёмом: " << users[maxIdx]
         << " (" << totalSize[maxIdx] << " байт)" << endl;

    // Формирование архива
    ofstream fout("archive.txt");
    for (int i = 0; i < n; i++) {
        if (strcmp(files[i].user, users[maxIdx]) == 0) {
            fout << files[i].user << " "
                 << files[i].filename << " "
                 << files[i].size << endl;
        }
    }
    fout.close();

    cout << "Файлы пользователя " << users[maxIdx]
         << " записаны в archive.txt" << endl;

    return 0;
}
