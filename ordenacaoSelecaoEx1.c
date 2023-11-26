#include <stdio.h>
#include "minhalib.h"

int main() {
    int arr[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sequência original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Sequência ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}