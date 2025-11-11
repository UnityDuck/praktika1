#include <stdio.h>
#include <string.h>

struct FileInfo {
    char user[50];
    char filename[100];
    int size;
};

int main(int argc, char *argv[]) {
    const int MAX = 1000;
    struct FileInfo files[MAX];
    int n = 0;

    FILE* fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Не удалось открыть файл input.txt\n");
        return 1;
    }

    // Считывание данных
    while (fscanf(fin, "%49s %99s %d", files[n].user, files[n].filename, &files[n].size) == 3) {
        n++;
        if (n >= MAX) break;
    }
    fclose(fin);

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

    printf("Пользователь с наибольшим объёмом: %s (%d байт)\n", users[maxIdx], totalSize[maxIdx]);

    // Формирование архива
    FILE* fout = fopen("archive.txt", "w");
    for (int i = 0; i < n; i++) {
        if (strcmp(files[i].user, users[maxIdx]) == 0) {
            fprintf(fout, "%s %s %d\n", files[i].user, files[i].filename, files[i].size);
        }
    }
    fclose(fout);

    printf("Файлы пользователя %s записаны в archive.txt\n", users[maxIdx]);

    return 0;
}
