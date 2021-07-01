#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "rus");
    srand(time(0));

    unsigned arr[901], temp;
    arr[900] = 1000;
    //генерация массива
    printf("Массив:\n");
    for (unsigned i = 0; i < 900; i++) {
        arr[i] = rand() % 900 + 100;
        printf("%u ", arr[i]);
    }
    //сортировка пузырьком
    for (unsigned i = 0; i < 900 - 1; i++) {
        for (unsigned j = 0; j < 900 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nОтсортированный массив:\n");
    for (unsigned i = 0; i < 900; i++) {
        printf("%u ", arr[i]);
    }
    printf("\nСписок отсутствующих трёхзначных чисел:\n");
    //вывод пропущенных числел
    temp = 99;
    for (unsigned i = 0; i < 901; i++) {
        for (unsigned j = temp + 1; j < arr[i]; j++) {
            printf("%u ", j);
        }
        temp = arr[i];
    }

}