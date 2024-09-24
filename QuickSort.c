#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[SIZE];
    srand(time(0));

    // Generar números aleatorios
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;  // Números entre 0 y 99
    }

    printf("Arreglo original: \n");
    printArray(arr, SIZE);

    quickSort(arr, 0, SIZE - 1);

    printf("Arreglo ordenado con Quick Sort: \n");
    printArray(arr, SIZE);

    return 0;
}