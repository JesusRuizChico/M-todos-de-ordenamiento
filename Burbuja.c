#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    bubbleSort(arr, SIZE);

    printf("Arreglo ordenado con Metodo Burbuja: \n");
    printArray(arr, SIZE);

    return 0;
}