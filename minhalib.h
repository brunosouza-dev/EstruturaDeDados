#include<stdio.h>

int sum(int a, int b) {    
    int r = a + b;
    printf("The sum is: %d", r);
    return r;
  }

int dezPct(int a) {
  double r = a * 0.1;
  printf("Ten percent of value is: %.2f", r);
  return r;
}

void imprimirArrays(int *array, int tamanho, char *nome) {
  printf("\nArray '%s': [", nome);
  for (int i = 0; i < tamanho; i++) {
    //Imprimir apenas números diferentes de 0
    if (array[i] != 0) {
      printf("%d", array[i]);
      //Verificando se o índice atual não é o último, para que após o último elemento fique sem a ','.
      if (i < tamanho - 1) {
        printf(", ");
      }
    }
  }
  printf("]\n");
}

void modificarArrays(int *array, int tamanho) {
  for(int i = 0; i < tamanho; i++) {
    array[i] = array[i] * 2;
  }
}

// void *criarArray(int tamanho) {
//   // malloc: reserva memória dinamicamente em tempo de execução.
//   int *array = malloc(tamanho * sizeof(int));
// 
//   for(int i = 0; i < tamanho; i++) {
//     array[i] = 2 * i + 3;
// 
//     return array;
//   }
// }

void imprimirArraysFloat(float *array, int tamanho, char *nome) {
  printf("\nArray '%s': [", nome);
  for (int i = 0; i < tamanho; i++) {
    //Imprimir apenas números diferentes de 0
    if (array[i] != 0) {
      printf("%.2f", array[i]);
      //Verificando se o índice atual não é o último, para que após o último elemento fique sem a ','.
      if (i < tamanho - 1) {
        printf(", ");
      }
    }
  }
  printf("]\n");
}

void imprimirStruct(int idade, int tamanho, char *nome) {
  printf("\n%dª pessoa: [", tamanho);
  printf("Nome: %s, ", nome);
  printf("idade: %d", idade);
  printf("]\n");
}

//Definição da estrutura funcionário para utilizar como parâmetro na função imprimirStructSalario
struct x {
  char nome[30];
  float salario;
}y;

void imprimirStructSalario(struct x y[], int tamanho) {
    printf("\nLista de funcionarios:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%dª pessoa: Nome: %s, salario: %.2f]\n", i+1, y[i].nome, y[i].salario);
    }
    printf("\n");
}

void ordenarArray(int *array, int tamanho) {
  int i, j, temp; 
  //laço for que percorre o array do início até o penúltimo elemento.
  for (i = 0; i < tamanho - 1; i++) { 
    //laço for que percorre o array do início até o penúltimo elemento a cada iteração de i. O -i subtrai os elementos que já estão na posição correta. O -1 é pra evitar que o índice j+1 acesse um elemento que não existe.
    for (j = 0; j < tamanho - i - 1; j++) { 
      //verifica se o elemento atual é maior que o próximo elemento, caso seja, ele vai sendo substituido de forma que o maior sempre seja colocado adiante.
      if (array[j] > array[j+1]) { 
        //uttiliza-se a variavel auxiliar temp pra passar o maior adiante e o menor para a posição atual.
        temp = array[j]; 
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}

// Funções de ordenação 

// Algoritmo de ordenação por seleção
void selectionSort(int array[], int n) {
    int i, j, minIndex, temp;

    // Loop externo percorre o array a partir do primeiro elemento até o penúltimo.
    for (i = 0; i < n - 1; i++) {
        minIndex = i;  // Suponha que o elemento atual seja o menor.

        // Loop interno percorre o array a partir do próximo elemento após i até o último.
        for (j = i + 1; j < n; j++) {
            // Compara o elemento atual com o menor elemento encontrado até agora.
            if (array[j] < array[minIndex]) {
                minIndex = j;  // Se um novo mínimo for encontrado, atualize minIndex.
            }
        }

        // Após encontrar o menor elemento, troca-o com o elemento na posição i.
        if (minIndex != i) {
            temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

// Algoritmo de ordenação por inserção
void insertionSort(int array[], int n) {
    int i, key, j;

    // Loop externo percorre o array a partir do segundo elemento até o último.
    for (i = 1; i < n; i++) {
        key = array[i];  // Captura o valor do elemento atual.
        j = i - 1;

        // Loop interno move os elementos maiores do que a chave uma posição à direita.
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        // Insere o elemento key na posição correta no subarray ordenado.
        array[j + 1] = key;
    }
}

void insertionSortDec(int arr[], int n) {
    int i, key, j;

    // Loop externo percorre o array a partir do segundo elemento até o último.
    for (i = 1; i < n; i++) {
        key = arr[i];  // Captura o valor do elemento atual.
        j = i - 1;

        // Loop interno move os elementos maiores do que key uma posição à direita.
        while (j >= 0 && arr[j] < key) {  // Comparação invertida para ordenação decrescente.
            arr[j + 1] = arr[j];
            j--;
        }

        // Insere o elemento key na posição correta no subarray ordenado.
        arr[j + 1] = key;
    }
}