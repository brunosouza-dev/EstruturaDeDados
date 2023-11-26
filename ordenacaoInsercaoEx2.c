#include <stdio.h>
#include "minhalib.h"

int main() {
  int arr[] = {62, 12, 25, 88, 11, 21, 44};
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("Sequência original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSortDec(arr, n);

    printf("Sequência ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}