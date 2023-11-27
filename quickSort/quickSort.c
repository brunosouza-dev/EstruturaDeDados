#include <stdio.h>
#include <string.h>

// Função para trocar dois ponteiros para strings
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o vetor
int partition(char *arr[], int low, int high) {
    // Escolhe o último elemento como o pivô
    char *pivot = arr[high];
    int i = low - 1;

    // Percorre o vetor
    for (int j = low; j < high; j++) {
        // Compara as strings usando strcmp
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            // Se a string atual for menor que o pivô, troca as posições
            swap(&arr[i], &arr[j]);
        }
    }

    // Coloca o pivô na posição correta
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Função de ordenação Quicksort
void quicksort(char *arr[], int low, int high) {
    if (low < high) {
        // Encontra o índice do pivô
        int pivotIndex = partition(arr, low, high);

        // Ordena os elementos antes e depois do pivô
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor Original:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    // Chama a função Quicksort para ordenar o vetor
    quicksort(arr, 0, n - 1);

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    // Calcula o número de trocas e comparações
    printf("Numero de Trocas: %d\n", n - 1);
    printf("Numero de Comparacoes: %d\n", (n - 1) * (n - 1) / 2);

    // Encontra a mediana
    char *mediana = arr[n / 2];
    printf("Mediana: %s\n", mediana);

    // Gera um arquivo de saída com os dados ordenados
    FILE *saida = fopen("Saida.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(saida, "%s\n", arr[i]);
    }

    fclose(saida);

    return 0;
}

